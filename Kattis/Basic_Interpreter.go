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
	lexLPAREN
	lexRPAREN
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
	case l.accept("("):
		return l.emit(lexLPAREN)
	case l.accept(")"):
		return l.emit(lexRPAREN)
	}
	return l.emit(lexEOF)
}

func (l *lexer) acceptRun(a string) {
	for l.accept(a) {
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
	if p.peek(t) {
		p.next()
		return true
	}
	return false
}

func (p *parser) app(f func(lexType) bool, t... lexType) bool {
	for _, tt := range t {
		if f(tt) {
			return true
		}
	}
	return false
}
func (p *parser) peekR(t ...lexType) bool { return p.app(p.peek, t...) }
func (p *parser) acceptR(t ...lexType) bool { return p.app(p.accept, t...) }

func (p *parser) parseLine() (*lineSt, error) {
	defer untrace(trace("parse line"))
	label, err := p.parseInt()
	if err != nil {
		return nil, fmt.Errorf("Line doesn't begin with label")
	}
	st, err := p.parseStatement()
	if err != nil {
		return nil, err
	}
	line := &lineSt{
		label: label,
		st: st,
	}
	return line, nil
}

func (p *parser) parseStatement() (Statement, error) {
	defer untrace(trace("parse statement"))
	// let statement

	if p.peek(lexLET) {
		return p.parseLet()
	}

	if p.peek(lexIF) {
		return p.parseIf()
	}

	if p.peek(lexPRINT) {
		return p.parsePstmt()
	}

	if p.peek(lexPRINTLN) {
		return p.parsePlnstmt()
	}

	if p.peek(lexGOTO) {
		return p.parseGOTO()
	}

	return nil, fmt.Errorf("Unexpected token %v", p.cur)
}

func (p *parser) parseGOTO() (Statement, error) {
	defer untrace(trace("parse goto"))
	p.accept(lexGOTO)
	v, err := p.parseInt()
	if err != nil {
		return nil, err
	}
	return &gotoSt{label: int(v.val)}, nil
}

func (p *parser) parseLet() (Statement, error) {
	defer untrace(trace("parse let"))
	p.accept(lexLET)
	l := &letStatement{
		ident: p.parseIdent(),
	}
	if err := p.expect(lexEQ); err != nil {
		return nil, err
	}
	a, err := p.parseExpression()
	if err != nil {
		return nil, err
	}
	l.expr = a
	return l, nil
}

func (p *parser) parseIf() (Statement, error) {
	defer untrace(trace("parse if"))
	p.accept(lexIF)
	b, err := p.parseExpression()
	if err != nil {
		return nil, err
	}
	c := &ifStatement{
		cond: b,
	}
	if err := p.expect(lexTHEN); err != nil {
		return nil, err
	}
	st, err := p.parseStatement()
	if err != nil {
		return nil, err
	}
	c.st = st
	return c, nil
}

/*
* Expression = Sum | Sum cmp Expression
* cmp = [> < <= >= <> =]
* Sum = Factor | Factor [+ -] Sum
* Factor = At | At [* /] Factor
* At = int | ident | (Expression)
*/
func(p *parser) parseExpression() (Expression, error) {
	defer untrace(trace("parse expression"))
	l, err := p.parseSum()
	if err != nil {
		return nil, fmt.Errorf("Error parsing expression: %v", err)
	}
	if !p.peekR(lexLT, lexGT, lexGTE, lexLTE, lexEQ, lexNEQ) {
		return l, nil
	}
	op := p.cur.Lit
	p.acceptR(lexLT, lexGT, lexGTE, lexLTE, lexEQ, lexNEQ)
	r, err := p.parseExpression()
	if err != nil {
		return nil, fmt.Errorf("Error parsing expression: %v", err)
	}
	return &boolExpr{
		left: l,
		right: r,
		op: op,
	}, nil
}

func (p *parser) parseSum() (Expression, error) {
	defer untrace(trace("parse sum"))
	l, err := p.parseFactor()
	if err != nil {
		return nil, err
	}
	if !p.peekR(lexPLUS, lexMINUS) {
		return l, nil
	}
	op := p.cur.Lit
	p.acceptR(lexPLUS, lexMINUS)
	r, err := p.parseSum()
	if err != nil {
		return nil, err
	}
	return &arithExpr{
		left: l,
		right: r,
		op: op,
	}, nil
}

func (p *parser) parseFactor() (Expression, error) {
	defer untrace(trace("parse factor"))
	l, err := p.parseAt()
	if err != nil {
		return nil, err
	}
	if !p.peekR(lexTIMES, lexDIV) {
		return l, nil
	}
	op := p.cur.Lit
	p.acceptR(lexTIMES, lexDIV)
	r, err := p.parseFactor()
	if err != nil {
		return nil, err
	}
	return &arithExpr{
		left: l,
		right: r,
		op: op,
	}, nil
}

func (p *parser) parseAt() (Expression, error) {
	defer untrace(trace("parse Atom"))
	if p.peek(lexINT) || p.peek(lexMINUS) {
		return p.parseInt()
	}
	if p.peek(lexIDENT) {
		return p.parseIdent(), nil
	}
	if p.accept(lexLPAREN) {
		st, err := p.parseExpression()
		if err != nil {
			return nil, err
		}
		err = p.expect(lexRPAREN)
		if err != nil {
			return nil, err
		}
		return st, nil
	}
	return nil, fmt.Errorf("Unexpected token: %v", p.cur)
}

func (p *parser) parseIdent() *ident {
	defer untrace(trace("parse ident"))
	defer p.accept(lexIDENT)
	return &ident{lit: p.cur.Lit}
}

func (p *parser) parseInt() (*intLit, error) {
	inv := p.accept(lexMINUS)
	v, err := func() (int64, error) {
		if inv {
			return strconv.ParseInt("-"+p.cur.Lit, 10, 32)
		}
		return strconv.ParseInt(p.cur.Lit, 10, 32)
	}()
	if err != nil {
		return nil, err
	}
	p.accept(lexINT)
	return &intLit{val: int32(v)}, nil
}

func (p *parser) parsePstmt() (*prSt, error) {
	defer untrace(trace("parse print statement"))
	p.accept(lexPRINT)
	if p.peek(lexSTRING) {
		return &prSt{s: p.parseString()}, nil
	}
	st, err := p.parseExpression()
	if err != nil {
		return nil, err
	}
	return &prSt{s:st}, nil
}

func (p *parser) parsePlnstmt() (*prlnSt, error) {
	defer untrace(trace("parse println statement"))
	p.accept(lexPRINTLN)
	if p.peek(lexSTRING) {
		return &prlnSt{s: p.parseString()}, nil
	}
	st, err := p.parseExpression()
	if err != nil {
		return nil, err
	}
	return &prlnSt{s:st}, nil
}

func (p *parser) parseString() *strLit {
	defer p.accept(lexSTRING)
	return &strLit{lit: p.cur.Lit[1 : len(p.cur.Lit)-1]}
}

// END PARSER ----------------------------------------------------------------------------------------------------

// BEGIN AST ----------------------------------------------------------------------------------------------------

type Statement interface {
	Execute() (Jmp, error)
}

type Expression interface {
	Type() valType
	Eval() (Val, error)
}

type lineSt struct {
	label *intLit
	st    Statement
}

func (l *lineSt) Execute() (Jmp, error) {
	return l.st.Execute()
}

type letStatement struct {
	ident *ident
	expr  Expression
}

func (l *letStatement) Execute() (Jmp, error) {
	a, err := l.expr.Eval()
	if err != nil {
		return nil, err
	}
	env[l.ident.lit] = a
	return cont, nil
}

type ifStatement struct {
	cond Expression
	st   Statement
}

func (f *ifStatement) Execute() (Jmp, error) {
	b, err := f.cond.Eval()
	if err != nil {
		return nil, err
	}
	if b.Type() != valBool {
		return nil, fmt.Errorf("Boolean value required")
	}
	bb := b.(*boolVal)
	if bb.Value {
		return f.st.Execute()
	}
	return cont, nil
}

type gotoSt struct {
	label int
}

func (g *gotoSt) Execute() (Jmp, error) {
	return GOTO(g.label), nil
}

type prSt struct{ s Expression }

func (p *prSt) Execute() (Jmp, error) {
	v, err := p.s.Eval()
	if err != nil {
		return nil, err
	}
	fmt.Printf("%v", v)
	return cont, nil
}

type prlnSt struct{ s Expression }

func (p *prlnSt) Execute() (Jmp, error) {
	v, err := p.s.Eval()
	if err != nil {
		return nil, err
	}
	fmt.Println(v)
	return cont, nil
}

type arithExpr struct {
	left  Expression
	right Expression
	op    string
}

func (a *arithExpr) Type() valType { return valInt }

func (a *arithExpr) Eval() (Val, error) {
	if a.left.Type() != valInt || a.right.Type() != valInt {
		return nil, fmt.Errorf("Incorrect types for arithmetic operation")
	}
	le, err := a.left.Eval()
	if err != nil {
		return nil, err
	}
	re, err := a.right.Eval()
	if err != nil {
		return nil, err
	}
	l := le.(*intVal)
	r := re.(*intVal)
	return &intVal{Value: mathOps[a.op](l.Value, r.Value)}, nil
}

type boolExpr struct {
	left  Expression
	right Expression
	op    string
}

func (a *boolExpr) Type() valType { return valInt }

func (a *boolExpr) Eval() (Val, error) {
	if a.left.Type() != valInt || a.right.Type() != valInt {
		return nil, fmt.Errorf("Incorrect types for boolean operation")
	}
	le, err := a.left.Eval()
	if err != nil {
		return nil, err
	}
	re, err := a.right.Eval()
	if err != nil {
		return nil, err
	}
	l := le.(*intVal)
	r := re.(*intVal)
	return &boolVal{Value: boolOps[a.op](l.Value, r.Value)}, nil
}

type ident struct{ lit string }

func (a *ident) Type() valType      { return a.Get().Type() }
func (a *ident) Eval() (Val, error) { return a.Get(), nil }

func (a *ident) Get() Val {
	if g, ok := env[a.lit]; ok {
		return g
	}
	return defVal
}

type intLit struct{ val int32 }

func (i *intLit) Type() valType      { return valInt }
func (i *intLit) Eval() (Val, error) { return &intVal{Value: i.val}, nil }

type strLit struct{ lit string }

func (i *strLit) Type() valType      { return valStr }
func (i *strLit) Eval() (Val, error) { return &strVal{i.lit}, nil }

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

type valType int32

const (
	valInt valType = iota
	valStr
	valBool
)

type Val interface {
	String() string
	Type() valType
}

type intVal struct {
	Value int32
}

func (i *intVal) Type() valType {
	return valInt
}

func (i *intVal) String() string {
	return fmt.Sprintf("%v", i.Value)
}

type strVal struct {
	Value string
}

func (s *strVal) Type() valType {
	return valStr
}

func (i *strVal) String() string {
	return fmt.Sprintf("%v", i.Value)
}

type boolVal struct {
	Value bool
}

func (i *boolVal) Type() valType {
	return valBool
}

func (i *boolVal) String() string {
	return fmt.Sprintf("%v", i.Value)
}

type Jmp func(int) int

func GOTO(l int) func(int) int {
	return func(int) int {
		return l
	}
}

func cont(i int) int {
	return nxt[i]
}

var defVal = &intVal{Value: 0}

// END EVAL ----------------------------------------------------------------------------------------------------

var (
	lines  = make(map[int]*lineSt)
	nxt    = make(map[int]int)
	lineNs []int
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		txt := scanner.Text()
		if len(txt) == 0 {
			continue
		}
		p := newParser(scanner.Text())
		st, err := p.parseLine()
		if err != nil {
			fmt.Fprintf(os.Stderr, "error parsing line: %v\n", err)
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
		v, err := lines[cur].Execute()
		if err != nil {
			fmt.Printf("Error while evaluating: %v\n", err)
			break
		}
		cur = v(cur)
	}
}
