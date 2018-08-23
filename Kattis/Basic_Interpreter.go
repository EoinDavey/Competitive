package main

import (
	"fmt"
	"strings"
)

const (
	alpha    = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
	num      = "0123456789"
	alphaNumSpace = alpha + num + " "
)

// BEGIN LEXER ---------------------------------------------------------------------------

type lexType int

const (
	lexEOF lexType = iota
	lexIF
	lexLET
	lexPRINT
	lexPRINTLN
	lexIDENT
	lexSTRING
	lexGOTO
	lexINT
	lexPLUS
	lexMINUS
	lexTIMES
	lexDIV
	lexEQ
	lexGT
	lexLT
	lexNEQ
	lexGTE
	lexLTE
	lexTHEN
)

type lexItem struct {
	Type lexType
	Lit  string
}

func (l lexItem) String() string {
	return fmt.Sprintf("(%d, %s)", l.Type, l.Lit)
}

type lexer struct {
	input   string
	start   int
	pos     int
	readPos int
	curCh   byte
}

func newLexer(in string) *lexer {
	l := &lexer{
		input: in,
	}
	l.nextChar()
	return l
}

func (l *lexer) nextChar() {
	l.pos = l.readPos
	if l.readPos >= 0 && l.readPos < len(l.input) {
		l.curCh = l.input[l.readPos]
		l.readPos++
	} else {
		l.curCh = 0
	}
}

func (l *lexer) ignoreWhitespace() {
	for l.curCh == ' ' {
		l.nextChar()
	}
	l.start = l.pos
}

func (l *lexer) accept(a string) bool {
	if strings.IndexByte(a, l.curCh) >= 0 {
		l.nextChar()
		return true
	}
	return false
}

func (l *lexer) emit(t lexType) lexItem {
	i := lexItem{Type: t, Lit: l.input[l.start:l.pos]}
	l.start = l.readPos
	return i
}

func (l *lexer) next() lexItem {
	l.ignoreWhitespace()

	// numbers
	if l.accept(num) {
		l.acceptRun(num)
		return l.emit(lexINT)
	}

	// identifer or func
	if l.accept(alpha) {
		l.acceptRun(alpha)
		switch l.input[l.start:l.pos] {
		case "IF":
			return l.emit(lexIF)
		case "LET":
			return l.emit(lexLET)
		case "PRINTLN":
			return l.emit(lexPRINTLN)
		case "PRINT":
			return l.emit(lexPRINT)
		case "GOTO":
			return l.emit(lexGOTO)
		case "THEN":
			return l.emit(lexTHEN)
		default:
			return l.emit(lexIDENT)
		}
	}

	if l.accept("<") {
		if l.accept("=") {
			return l.emit(lexLTE)
		}
		if l.accept(">") {
			return l.emit(lexNEQ)
		}
		return l.emit(lexLT)
	}

	if l.accept(">") {
		if l.accept("=") {
			return l.emit(lexGTE)
		}
		return l.emit(lexGT)
	}

	// string literal
	if l.accept("\"") {
		l.acceptRun(alphaNumSpace)
		l.accept("\"")
		return l.emit(lexSTRING)
	}

	switch true {
	case l.accept("+"):
		return l.emit(lexPLUS)
	case l.accept("-"):
		return l.emit(lexMINUS)
	case l.accept("*"):
		return l.emit(lexTIMES)
	case l.accept("/"):
		return l.emit(lexDIV)
	case l.accept("="):
		return l.emit(lexEQ)
	}
	return l.emit(lexEOF)
}

func (l *lexer) acceptRun(a string) {
	for strings.IndexByte(a, l.curCh) >= 0 {
		l.nextChar()
	}
}

// END LEXER -------------------------------------------------------------------------------------------------------

// BEGIN PARSER ----------------------------------------------------------------------------------------------------
type parser struct {
	l *lexer
	cur lexItem
}

func newParser(s string) *parser {
	p := &parser{
		l: newLexer(s),
	}
	p.next()
	return p
}

func (p *parser) next() {
	p.cur = p.l.next()
}

func (p *parser) expect(t lexType) error {
	if p.cur.Type != t {
		return fmt.Errorf("Type %d not %d", p.cur.Type, t)
	}
	p.next()
	return nil
}

func (p *parser) accept(t lexType) bool {
	defer untrace(trace(fmt.Sprintf("accept(%v), %v",t, p.cur)))
	if p.cur.Type == t {
		pD();
		p.next()
		return true
	}
	return false
}

func (p *parser) parseLine() bool {
	defer untrace(trace("parse line"));
	if err := p.expect(lexINT); err != nil {
		return false
	}

	// let statement
	if p.accept(lexLET) {
		if err := p.expect(lexIDENT); err != nil {
			return false
		}
		if err := p.expect(lexEQ); err != nil {
			return false
		}
		if !p.parseArith() {
			return false
		}
		return true
	}

	if p.accept(lexIF) {
		if !p.parseCond() {
			return false
		}
		if err := p.expect(lexTHEN); err != nil {
			return false
		}
		if err := p.expect(lexGOTO); err != nil {
			return false
		}
		if err := p.expect(lexINT); err != nil {
			return false
		}
		return true
	}
	if p.accept(lexPRINT) {
		if !p.parsePstmt() {
			return false
		}
		return true
	}
	if p.accept(lexPRINTLN) {
		if !p.parsePstmt() {
			return false
		}
		return true
	}
	return false
}

func (p *parser) parseArith() bool {
	defer untrace(trace("parse arithmetic statement"));
	if !p.accept(lexINT) && !p.accept(lexIDENT) {
		return false
	}

	if p.accept(lexPLUS) || p.accept(lexMINUS) ||
		p.accept(lexTIMES) || p.accept(lexDIV) {

		if !p.accept(lexINT) && !p.accept(lexIDENT) {
			return false
		}
	}
	return true
}

func (p *parser) parseCond() bool {
	defer untrace(trace("parse conditional statement"));
	if !p.accept(lexINT) && !p.accept(lexIDENT) {
		return false
	}

	if !p.accept(lexGT) && !p.accept(lexGTE) &&
		!p.accept(lexLT) && !p.accept(lexLTE) {
		return false
	}

	if !p.accept(lexINT) && !p.accept(lexIDENT) {
		return false
	}

	return true
}

func (p *parser) parsePstmt() bool {
	defer untrace(trace("parse print statement"));
	if !p.accept(lexSTRING) && !p.accept(lexIDENT) {
		return false
	}
	return true
}

// END PARSER ----------------------------------------------------------------------------------------------------
// BEGIN TRACER ----------------------------------------------------------------------------------------------------

var traceDepth = -1
var traceActive = false

func pD(){
	if traceActive {
		for i := 0; i < traceDepth; i++ {
			fmt.Printf("  ");
		}
	}
}

func untrace(msg string) {
	if traceActive {
		pD();
		fmt.Println("END %s", msg)
		traceDepth--
	}
}

func trace(msg string) string {
	if traceActive {
		traceDepth++
		pD();
		fmt.Printf("BEGIN %s\n", msg)
	}
	return msg
}

// END TRACER ----------------------------------------------------------------------------------------------------

func main() {
	for _, test := range []struct {
		in  string
		out []string
	}{
		{
			in:  " 5 0123 45    67",
			out: []string{"(8, 5)", "(8, 0123)", "(8, 45)", "(8, 67)"},
		},
		{
			in:  "IF 5",
			out: []string{"(1, IF)", "(8, 5)"},
		},
		{
			in:  "IF  PRINT  PRINTLN   LET  X",
			out: []string{"(1, IF)", "(3, PRINT)", "(4, PRINTLN)", "(2, LET)", "(5, X)"},
		},
		{
			in:  "<> + - * / > < >= <=",
			out: []string{"(16, <>)", "(9, +)", "(10, -)", "(11, *)", "(12, /)", "(14, >)", "(15, <)", "(17, >=)", "(18, <=)"},
		},
		{
			in:  "LET X = \"testy tests\"",
			out: []string{"(2, LET)", "(5, X)", "(13, =)", "(6, \"testy tests\")"},
		},
	} {
		l := newLexer(test.in)
		out := []string{}
		for t := l.next(); t.Type != lexEOF; t = l.next() {
			out = append(out, t.String())
		}
		if len(out) != len(test.out) {
			fmt.Printf("len(out) != len(test.out), %d != %d\n", len(out), len(test.out))
			break
		}
		for i := range out {
			if out[i] != test.out[i] {
				fmt.Printf("Token mismatch: %v != %v\n", out[i], test.out[i])
			}
		}
	}
	for _, test := range []struct {
		in  string
		valid bool
	}{
		{
			in: "10 LET a = 1",
			valid: true,
		},
		{
			in: "20 PRINT \"HELLO THERE\"",
			valid: true,
		},
		{
			in: "30 PRINTLN A",
			valid: true,
		},
		{
			in: "40 LET A = A + 1",
			valid: true,
		},
		{
			in: "50 IF A <= 5 THEN GOTO 20",
			valid: true,
		},
		{
			in: "60 PRINTLN \"DONE\"",
			valid: true,
		},
		{
			in: "10 La = 1",
			valid: false,
		},
	} {
		p := newParser(test.in)
		if p.parseLine() != test.valid {
			fmt.Println("Failed on %s", test.in)
			traceActive = true
			p = newParser(test.in)
			p.parseLine()
			traceActive = false
		}
	}
}
