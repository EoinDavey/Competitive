from math import factorial

def solution(w, h, s):
    wp = parts(w)
    hp = parts(h)

    for wx in wp:
        for hx in hp:
            pass

smemo = {}
def stirling(n, k):
    if n == 0 and k == 0:
        return 1
    if n == 0 or k == 0:
        return 0
    if (n, k) not in smemo:
        smemo[(n,k)] = (n-1)*stirling(n-1, k) + stirling(n-1, k-1)
    return smemo[(n, k)]

cmemo = {}
def nck(n, k):
    if n == 0:
        return k == 0
    if k == 0:
        return 1
    if (n, k) not in cmemo:
        cmemo[(n, k)] = nck(n-1, k-1) + nck(n-1, k)
    return cmemo[(n,k)]

def parts(n):
    o = []
    s = set()

    def rec(n):
        if n == 0:
            s.add(tuple(sorted(o)))
        for i in xrange(1, n+1):
            o.append(i)
            rec(n-i)
            o.pop()

    return s
