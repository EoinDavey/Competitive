import sys
from collections import Counter, deque, defaultdict

def accept(c):
    global cur, l
    if cur==c:
        cur = next(l)
        return True
    return False

def expect(c):
    global cur, l
    assert(cur==c)
    cur = next(l)

def eat():
    global cur, l
    if cur==')':
        return ''
    c = cur
    cur = next(l)
    return c

# OPT = CAT | CAT '|' OPT
# CAT = TOK | TOK CAT

def opt(d):
    t = {}
    t['t'] = 'opt'
    l = cat(d+1)
    t['l'] = l
    if accept('|'):
        r = opt(d+1)
        t['r'] = r
    return t

def cat(d):
    t = {}
    t['t'] = 'cat'
    l = tok(d+1)
    t['l'] = l
    if cur != '\0' and cur != ')' and cur != '|':
        r = cat(d+1)
        t['r'] = r
    return t


def tok(d):
    if accept('('):
        r = opt(d+1)
        expect(')')
        return r
    t = {}
    t['t'] = 'tok'
    t['v'] = eat()
    return t

def solve(t, x, y):
    if t['t'] == 'cat':
        xs = solve(t['l'], x, y)
        if 'r' in t:
            o = []
            for nx, ny in xs:
                o+= solve(t['r'], nx, ny)
            return o
        else:
            return xs
    if t['t'] == 'opt':
        o = solve(t['l'], x, y)
        if 'r' in t:
            o+= solve(t['r'], x, y)
        return o
    if t['t'] == 'tok':
        for c in t['v']:
            if c=='E':
                x +=1
            if c=='W':
                x -=1
            if c=='N':
                y +=1
            if c=='S':
                y -=1
        return [(x,y)]

def gen(s):
    i = 0
    o = ""
    while i < len(s):
        while i < len(s) and s[i] >= 'A' and s[i] <= 'Z':
            o += s[i]
            i+=1
        yield o
        o = ""
        while i < len(s) and (s[i] < 'A' or s[i] > 'Z'):
            yield s[i]
            i+=1
    while True:
        yield '\0'

s = raw_input()[1:-1]
l = gen(s)
cur = next(l)
r =  cat(0)
print len(solve(r, 0, 0))
