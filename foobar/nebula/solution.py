def valid(lc, rc, ind, grid):
    l = [False]*(len(grid)+1)
    r = [False]*(len(grid)+1)
    for i in xrange(len(grid)+1):
        if (rc&(1<<i)) != 0:
            r[i] = True
    for i in xrange(len(grid)+1):
        if (lc&(1<<i)) != 0:
            l[i] = True
    for i in xrange(len(grid)):
        on = sum([l[i], r[i], l[i+1], r[i+1]]) == 1
        if on != grid[i][ind]:
            return False
    return True

memo = {}
def dp(col, ind, grid):
    if ind == len(grid[0]):
        return 1
    if (col, ind) in memo:
        return memo[(col, ind)]
    sm = 0
    for c in xrange(2**(len(grid)+1)):
        if valid(col, c, ind, grid):
            sm += dp(c, ind+1, grid)
    memo[(col, ind)] = sm
    return sm

def solution(g):
    global memo
    memo = {}
    sm = 0
    for i in xrange(2**(len(g)+1)):
        sm += dp(i, 0, g)
    return sm
