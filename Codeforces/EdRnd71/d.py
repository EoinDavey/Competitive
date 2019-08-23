MOD = 998244353

def getFacs(lim):
    facs = [1]*lim
    for i in range(1, lim):
        facs[i] = (i * facs[i-1]) % MOD
    return (lambda x: facs[x])

def permCount(ls): # ls must be sorted
    n = 1
    l = 0
    while l < len(ls):
        run = 1
        while l+1  < len(ls) and ls[l+1] == ls[l]:
            run+=1
            l+=1
        n = (n * factorial(run)) % MOD
        l+=1
    return n

def overlapCount(ls):
    l = 0
    n = 1
    while l < len(ls):
        strt = l
        while l + 1 < len(ls) and ls[l + 1][0] == ls[l][0]:
            l += 1
        end = l
        n = (n * permCount([ls[x][1] for x in range(strt, end+1)])) % MOD
        l += 1
    return n

def isSorted(ls):
    for i in range(len(ls)-1):
        if ls[i] > ls[i+1]:
            return False
    return True

def sub(a, b):
    return ((a-b) % MOD + MOD) % MOD

N = int(input())
factorial = getFacs(N+2)

o = [[int(x) for x in input().split()] for _ in range(N)]
o.sort()

firsts = [x[0] for x in o]
seconds = [x[1] for x in o]

d = 0
if isSorted(firsts) and isSorted(seconds):
    d = overlapCount(o)

firsts.sort()
seconds.sort()
fcnt = permCount(firsts)
scnt = permCount(seconds)

print(sub(factorial(N), sub(fcnt + scnt, d)))
