from collections import Counter

def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    c = Counter(a)
    for (a, b) in c.most_common():
        if b%2 != 0:
            print("NO")
            return
    ls = [a for (a,b) in c.most_common() for _ in range(b//2)]
    ls.sort()
    l, r = 0, len(ls)-1
    s = set()
    while l < r:
        s.add(ls[l]*ls[r])
        l+=1
        r-=1
    if len(s) == 1:
        print("YES")
    else:
        print("NO")

for _ in range(int(input())):
    solve()
