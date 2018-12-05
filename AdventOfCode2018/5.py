import sys
from collections import Counter

s = list(raw_input())

def dest(a,b):
    return ord(a)-ord('a') == ord(b) - ord('A') or ord(b)-ord('a') == ord(a) - ord('A')

def slv(s):
    stk = []
    for c in s:
        if stk and dest(stk[-1],c):
            stk.pop()
        else:
            stk.append(c)
    return len(stk)

mn = 10**19
ans = 'a'
for c in xrange(26):
    x = chr(c+ord('a'))
    ns = []
    for g in s:
        if g.lower() != x:
            ns.append(g)
    v = slv(ns)
    mn = min(mn, v)
print mn
