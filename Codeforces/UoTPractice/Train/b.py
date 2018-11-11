'''
0 1 2 1, 0 1 2 1, 0

1
9 3
3 4 2

1
6 5

0 1 2 3 4 3 2 
'''

T = input()
for _ in xrange(T):
    x, n = map(int, raw_input().split())

    if n == 1:
        print x
        continue

    ln = 2*n-2

    runs = x/ln

    ans = [0]*n
    for i in xrange(n):
        sz = runs*(1 if i == 0 or i ==n-1 else 2)
        ans[i] += sz
        x-=sz
    for i in xrange(n):
        if x:
            ans[i] += 1
            x-=1
    for i in xrange(n-2, -1, -1):
        if x:
            ans[i] += 1
            x-=1
    print ' '.join(map(str, ans))
