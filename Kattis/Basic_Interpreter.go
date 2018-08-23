package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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
    inv := p.accept(lexMINUS)
	v, err := strconv.ParseInt(p.cur.Lit, 10, 32)
	if err != nil {
		return nil, err
	}
	i := func() *intLit {
        if inv {
            return &intLit{val: int32(v*-1)}
        }
        return &intLit{val: int32(v)}
    }()
	p.accept(lexINT)
	return i, nil
}

func (p *parser) parseArith() (Expression, error) {
	defer untrace(trace("parse arithmetic statement"))
	i, err := func() (Expression, error) {
		if p.peek(lexINT) || p.peek(lexMINUS) {
			i, err := p.parseInt()
			if err != nil {
				return nil, err
			}
			return i, nil
		} else if p.peek(lexIDENT) {
			return p.parseIdent(), nil
		} else {
			return nil, fmt.Errorf("Unexpected token %s, expected int or var", p.cur)
		}
	}()
	if err != nil {
		return nil, err
	}

	if p.peekR(lexPLUS, lexMINUS, lexTIMES, lexDIV) {
		a := &arithExpr{
			left: i,
		}
		a.op = p.cur.Lit

		p.acceptR(lexPLUS, lexMINUS, lexTIMES, lexDIV)

		if p.peek(lexINT) || p.peek(lexMINUS) {
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
		return a, nil
	}
	return i, nil
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

type Node interface {
	String() string
}

type Statement interface {
	Node
	statement()
}

type Expression interface {
	Node
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
	expr  Expression
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
// BEGIN EVAL ----------------------------------------------------------------------------------------------------

var env = make(map[string]Val)

var boolOps = map[string]func(int32, int32) bool{
	"<":  func(x, y int32) bool { return x < y },
	">":  func(x, y int32) bool { return x > y },
	">=": func(x, y int32) bool { return x >= y },
	"<=": func(x, y int32) bool { return x <= y },
	"<>": func(x, y int32) bool { return x != y },
	"=":  func(x, y int32) bool { return x == y },
}

var mathOps = map[string]func(int32, int32) int32{
	"+": func(x, y int32) int32 { return x + y },
	"-": func(x, y int32) int32 { return x - y },
	"*": func(x, y int32) int32 { return x * y },
	"/": func(x, y int32) int32 { return x / y },
}

type Val interface {
	String() string
}

type intVal struct {
	Value int32
}

func (i *intVal) String() string {
	return fmt.Sprintf("%v", i.Value)
}

type strVal struct {
	Value string
}

func (i *strVal) String() string {
	return fmt.Sprintf("%v", i.Value)
}

type boolVal struct {
	Value bool
}

func (i *boolVal) String() string {
	return fmt.Sprintf("%v", i.Value)
}

// continue to next line
type contValImpl struct{}

func (c *contValImpl) String() string {
	return fmt.Sprintf("Continue")
}

type jumpVal struct {
	label int32
}

func (j *jumpVal) String() string {
	return fmt.Sprintf("%v", j.label)
}

var contVal = &contValImpl{}

func Eval(n Node) (Val, error) {
	switch t := n.(type) {
	case *intLit:
		return &intVal{Value: t.val}, nil
	case *strLit:
		return &strVal{Value: t.lit}, nil
	case *ident:
		return env[t.lit], nil
	case *boolExpr:
		l, err := Eval(t.left)
		if err != nil {
			return nil, err
		}
		r, err := Eval(t.right)
		if err != nil {
			return nil, err
		}
		li, ok := l.(*intVal)
		if !ok {
			return nil, fmt.Errorf("Incorrect types")
		}
		ri, ok := r.(*intVal)
		if !ok {
			return nil, fmt.Errorf("Incorrect types")
		}
		return &boolVal{Value: boolOps[t.op](li.Value, ri.Value)}, nil
	case *arithExpr:
		l, err := Eval(t.left)
		if err != nil {
			return nil, err
		}
		r, err := Eval(t.right)
		if err != nil {
			return nil, err
		}
		li, ok := l.(*intVal)
		if !ok {
			return nil, fmt.Errorf("Incorrect types")
		}
		if r != nil {
			ri, ok := r.(*intVal)
			if !ok {
				return nil, fmt.Errorf("Incorrect types")
			}
			return &intVal{Value: mathOps[t.op](li.Value, ri.Value)}, nil
		} else {
			return &intVal{Value: li.Value}, nil
		}
	case *prSt:
		l, err := Eval(t.s)
		if err != nil {
			return nil, err
		}
		fmt.Printf(l.String())
		return contVal, nil
	case *prlnSt:
		l, err := Eval(t.s)
		if err != nil {
			return nil, err
		}
		fmt.Println(l.String())
		return contVal, nil
	case *ifStatement:
		c, err := Eval(t.cond)
		if err != nil {
			return nil, err
		}
		b := c.(*boolVal)
		if b.Value {
			return &jumpVal{label: t.label.val}, nil
		}
        return contVal, nil
	case *letStatement:
		a, err := Eval(t.expr)
		if err != nil {
			return nil, err
		}
		v := a.(*intVal)
		env[t.ident.lit] = v
		return contVal, nil
	case *lineSt:
		return Eval(t.st)
	}
	return nil, fmt.Errorf("Unknown type %T", n)
}

// END EVAL ----------------------------------------------------------------------------------------------------

func main() {
	lines := make(map[int]*lineSt)
	nxt := make(map[int]int)
	lineNs := []int{}
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		txt := scanner.Text()
		if len(txt) == 0 {
			continue
		}
		p := newParser(scanner.Text())
		st, err := p.parseLine()
		if err != nil {
			fmt.Fprintf(os.Stderr, "error parsing line: %v", err)
			continue
		}
		lineN := st.label.val
		lines[int(lineN)] = st
		lineNs = append(lineNs, int(lineN))
	}
	sort.Ints(lineNs)
	for i := 0; i < len(lineNs)-1; i++ {
		nxt[lineNs[i]] = lineNs[i+1]
	}
	nxt[lineNs[len(lineNs)-1]] = -1
	cur := lineNs[0]
	for {
		if cur == -1 {
			break
		}
		v, err := Eval(lines[cur])
		if err != nil {
			fmt.Printf("Error while evaluating: %v\n", err)
			break
		}
		switch t := v.(type) {
		case *contValImpl:
			cur = nxt[cur]
		case *jumpVal:
			cur = int(t.label)
		}
	}
}
