N = int(input())
ls = [int(x) for x in input().split()]
INF = 10**10

def mDiff(arr):
    sm = 0
    pref = [0]*N
    for i in range(N):
        pref[i] = arr[i] + (0 if i < 1 else pref[i-1])

    mn = 0
    mx = 0
    for i in range(N):
        mx = max(mx, pref[i] - mn)
        mn = min(mn, pref[i])
    return mx

print(max(mDiff(ls), mDiff([-x for x in ls])))
