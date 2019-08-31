def inp(): return int(input())
def ln(): return [int(x) for x in input().split()]

def solve():
    n = inp()
    a = ln()
    mns = [-1]*n
    mns[-1] = a[-1]
    for i in range(n-2,-1,-1):
        mns[i] = min(a[i], mns[i+1])

    cnt = 0
    for i in range(n):
        if i + 1 < n and mns[i+1] < a[i]:
            cnt += 1
    print(cnt)

for _ in range(inp()):
    solve()
