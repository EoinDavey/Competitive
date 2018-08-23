package main

import (
	"fmt"
	"strconv"
	"strings"
)

const (
	alpha         = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
	num           = "0123456789"
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
	l   *lexer
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

func (p *parser) peek(t lexType) bool {
	return p.cur.Type == t
}

func (p *parser) accept(t lexType) bool {
	defer untrace(trace(fmt.Sprintf("accept(%v), %v", t, p.cur)))
	if p.peek(t) {
		pD()
		p.next()
		return true
	}
	return false
}

func (p *parser) peekR(t ...lexType) bool {
	for _, tt := range t {
		if p.peek(tt) {
			return true
		}
	}
	return false
}

func (p *parser) acceptR(t ...lexType) bool {
	for _, tt := range t {
		if p.accept(tt) {
			return true
		}
	}
	return false
}

func (p *parser) parseLine() (*lineSt, error) {
	defer untrace(trace("parse line"))
	label, err := p.parseInt()
	if err != nil {
		return nil, fmt.Errorf("Line doesn't begin with label")
	}
	line := &lineSt{
		label: label,
	}

	// let statement
	if p.accept(lexLET) {
		l := &letStatement{
			ident: p.parseIdent(),
		}
		if err := p.expect(lexEQ); err != nil {
			return nil, err
		}
		a, err := p.parseArith()
		if err != nil {
			return nil, err
		}
		l.expr = a
		line.st = l
		return line, nil
	}

	// if
	if p.accept(lexIF) {
		b, err := p.parseCond()
		if err != nil {
			return nil, err
		}
		c := &ifStatement{
			cond: b,
		}
		if err := p.expect(lexTHEN); err != nil {
			return nil, err
		}
		if err := p.expect(lexGOTO); err != nil {
			return nil, err
		}
		i, err := p.parseInt()
		if err != nil {
			return nil, err
		}
		c.label = i
		line.st = c
		return line, nil
	}

	if p.accept(lexPRINT) {
		st, err := p.parsePstmt()
		if err != nil {
			return nil, err
		}
		line.st = st
		return line, nil
	}

	if p.accept(lexPRINTLN) {
		st, err := p.parsePlnstmt()
		if err != nil {
			return nil, err
		}
		line.st = st
		return line, nil
	}
	return nil, fmt.Errorf("Unexpected token %s", p.cur)
}

func (p *parser) parseIdent() *ident {
	defer untrace(trace("parse ident"))
	defer p.accept(lexIDENT)
	return &ident{lit: p.cur.Lit}
}

func (p *parser) parseInt() (*intLit, error) {
	v, err := strconv.ParseInt(p.cur.Lit, 10, 32)
	if err != nil {
		return nil, err
	}
	i := &intLit{val: int32(v)}
	p.accept(lexINT)
	return i, nil
}

func (p *parser) parseArith() (*arithExpr, error) {
	defer untrace(trace("parse arithmetic statement"))
	a := &arithExpr{}
	if p.peek(lexINT) {
		i, err := p.parseInt()
		if err != nil {
			return nil, err
		}
		a.left = i
	} else if p.peek(lexIDENT) {
		a.left = p.parseIdent()
	} else {
		return nil, fmt.Errorf("Unexpected token %s, expected int or var", p.cur)
	}

	if p.peekR(lexPLUS, lexMINUS, lexTIMES, lexDIV) {
		a.op = p.cur.Lit

		p.acceptR(lexPLUS, lexMINUS, lexTIMES, lexDIV)

		if p.peek(lexINT) {
			i, err := p.parseInt()
			if err != nil {
				return nil, err
			}
			a.right = i
		} else if p.peek(lexIDENT) {
			a.right = p.parseIdent()
		} else {
			return nil, fmt.Errorf("Unexpected token %s, expected int or var", p.cur)
		}
	}
	return a, nil
}

func (p *parser) parseCond() (*boolExpr, error) {
	defer untrace(trace("parse conditional statement"))
	b := &boolExpr{}
	if p.peek(lexINT) {
		i, err := p.parseInt()
		if err != nil {
			return nil, err
		}
		b.left = i
	} else if p.peek(lexIDENT) {
		b.left = p.parseIdent()
	} else {
		return nil, fmt.Errorf("Unexpected token %s, expected int or var", p.cur)
	}

	b.op = p.cur.Lit

	if !p.acceptR(lexGT, lexGTE, lexLT, lexLTE, lexEQ, lexNEQ) {
		return nil, fmt.Errorf("Expected < > <= <> = or >=")
	}

	if p.peek(lexINT) {
		i, err := p.parseInt()
		if err != nil {
			return nil, err
		}
		b.right = i
	} else if p.peek(lexIDENT) {
		b.right = p.parseIdent()
	} else {
		return nil, fmt.Errorf("Unexpected token %s, expected int or var", p.cur)
	}
	return b, nil
}

func (p *parser) parsePstmt() (*prSt, error) {
	defer untrace(trace("parse print statement"))
	if p.peek(lexSTRING) {
		return &prSt{s: p.parseString()}, nil
	}
	if p.peek(lexIDENT) {
		return &prSt{s: p.parseIdent()}, nil
	}
	return nil, fmt.Errorf("Unexpected token %s, expected string or var", p.cur)
}

func (p *parser) parsePlnstmt() (*prlnSt, error) {
	defer untrace(trace("parse printl statement"))
	if p.peek(lexSTRING) {
		return &prlnSt{s: p.parseString()}, nil
	}
	if p.peek(lexIDENT) {
		return &prlnSt{s: p.parseIdent()}, nil
	}
	return nil, fmt.Errorf("Unexpected token %s, expected string or var", p.cur)
}

func (p *parser) parseString() *strLit {
	defer p.accept(lexSTRING)
	return &strLit{lit: p.cur.Lit[1 : len(p.cur.Lit)-1]}
}

// END PARSER ----------------------------------------------------------------------------------------------------

// BEGIN AST ----------------------------------------------------------------------------------------------------

type Statement interface {
	statement()
}
type Expression interface {
	expression()
}

type lineSt struct {
	label *intLit
	st    Statement
}

func (l *lineSt) String() string {
	return fmt.Sprintf("%v (%v)", l.label, l.st)
}

type letStatement struct {
	ident *ident
	expr  *arithExpr
}

func (l *letStatement) statement() {}

func (l *letStatement) String() string {
	return fmt.Sprintf("LET %v = %v", l.ident, l.expr)
}

type ifStatement struct {
	cond  *boolExpr
	label *intLit
}

func (l *ifStatement) statement() {}

func (l *ifStatement) String() string {
	return fmt.Sprintf("IF(%v) THEN GOTO %v", l.cond, l.label)
}

type prSt struct {
	s Expression
}

func (l *prSt) statement() {}

func (l *prSt) String() string {
	return fmt.Sprintf("PRINT(%v)", l.s)
}

type prlnSt struct {
	s Expression
}

func (l *prlnSt) statement() {}

func (l *prlnSt) String() string {
	return fmt.Sprintf("PRINTLN(%v)", l.s)
}

type arithExpr struct {
	left  Expression
	right Expression
	op    string
}

func (b *arithExpr) expression() {}

func (b *arithExpr) String() string {
	return fmt.Sprintf("(%v) %s (%v)", b.left, b.op, b.right)
}

type boolExpr struct {
	left  Expression
	right Expression
	op    string
}

func (b *boolExpr) expression() {}

func (b *boolExpr) String() string {
	return fmt.Sprintf("(%v) %s (%v)", b.left, b.op, b.right)
}

type ident struct {
	lit string
}

func (i *ident) expression() {}

func (b *ident) String() string {
	return fmt.Sprintf("{{%s}}", b.lit)
}

type intLit struct {
	val int32
}

func (i *intLit) expression() {}

func (i *intLit) String() string {
	return fmt.Sprintf("%d", i.val)
}

type strLit struct {
	lit string
}

func (i *strLit) expression() {}

func (i *strLit) String() string {
	return fmt.Sprintf("\"%s\"", i.lit)
}

// END AST ----------------------------------------------------------------------------------------------------

// BEGIN TRACER ----------------------------------------------------------------------------------------------------

var traceDepth = -1
var traceActive = false

func pD() {
	if traceActive {
		for i := 0; i < traceDepth; i++ {
			fmt.Printf("  ")
		}
	}
}

func untrace(msg string) {
	if traceActive {
		pD()
		fmt.Println("END %s", msg)
		traceDepth--
	}
}

func trace(msg string) string {
	if traceActive {
		traceDepth++
		pD()
		fmt.Printf("BEGIN %s\n", msg)
	}
	return msg
}
func tracef(format string, args ...interface{}) {
	if traceActive {
		pD()
		fmt.Println(fmt.Sprintf(format, args...))
	}
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
		in    string
		valid bool
	}{
		{
			in:    "10 LET a = 1",
			valid: true,
		},
		{
			in:    "20 PRINT \"HELLO THERE\"",
			valid: true,
		},
		{
			in:    "30 PRINTLN A",
			valid: true,
		},
		{
			in:    "40 LET A = A + 1",
			valid: true,
		},
		{
			in:    "50 IF A <= 5 THEN GOTO 20",
			valid: true,
		},
		{
			in:    "60 PRINTLN \"DONE\"",
			valid: true,
		},
		{
			in:    "10 La = 1",
			valid: false,
		},
		{
			in:    "50 IF A <= 5 THEN 20",
			valid: false,
		},
		{
			in:    "40 LET A = A +",
			valid: false,
		},
	} {
		p := newParser(test.in)
		st, err := p.parseLine()
		fmt.Printf("st: %s\n%v\n", test.in, st)
		if (err == nil) != test.valid {
			fmt.Println("Failed on %s: %v", test.in, err)
			traceActive = true
			p = newParser(test.in)
			p.parseLine()
			traceActive = false
		}
	}
}
