def pr(d):
    s=""
    for _ in xrange(d):
        s+="  "
    return s

memo = {}
def f(n, cap, dpth):
    if n == 0:
        return 1
    if (n, cap) in memo:
        return memo[(n, cap)]
    sm = 0
    for i in xrange(1, min(n+1, cap)):
        sm += f(n-i, i, dpth+1)
    memo[(n,cap)] = sm
    return sm

def solution(n):
    return f(n, n+1, 0) - 1
