def iinp(): return int(input())

n = iinp()
a = [int(x) for x in input().split()]
memo = {
        (0, 1) : abs(a[0] - 1),
        (0, -1) : abs(a[0] + 1)
}

for ind in range(1, len(a)):
    for v in [-1, 1]:
        ans = min(abs(a[ind]-1) + memo[(ind - 1, v)], abs(a[ind] + 1) + memo[(ind - 1, v*-1)])
        memo[(ind,v)] = ans

print(memo[(len(a)-1, 1)])
