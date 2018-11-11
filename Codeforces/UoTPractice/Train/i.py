T = input()
for _ in xrange(T):
    x, n = map(int, raw_input().split())
    if n > x:
        print -1
        continue
    lwr = x/n
    upr = lwr if x%n==0 else lwr + 1
    ans = []
    for i in xrange(n):
        if lwr*i + (n-i)*upr == x:
            for j in xrange(i):
                ans.append(lwr)
            for j in xrange(n-i):
                ans.append(upr)
            print ' '.join(map(str, ans))
            break
