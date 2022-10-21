from collections import defaultdict

cnt = defaultdict(int)

n, l = [int(x) for x in input().split()]

ls = []
sm = 0
for _ in range(n):
    s = input()
    ls.append(s)

    for i in range(l):
        cnt[s[:i+1]] += 1 

for s in ls:
    for i in range(l):
        if cnt[s[:i+1]] == 1:
            sm += i+1
            break
print(sm)
