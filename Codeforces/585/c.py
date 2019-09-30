import sys
n = int(input())
s = input()
t = input()

if (s.count('a') + t.count('a')) % 2 or (s.count('b') + t.count('b')) % 2:
    print(-1)
    sys.exit(0)

ab, ba = 0, 0

for i in range(n):
    if s[i] == 'a' and t[i]=='b':
        ab += 1
    if s[i] == 'b' and t[i]=='a':
        ba += 1

pab, pba = -1, -1
mvs = []
for i in range(n):
    if s[i] == 'a' and t[i]=='b':
        if pab != -1:
            mvs.append((i, pab))
            pab = -1
        else:
            pab = i
    if s[i] == 'b' and t[i]=='a':
        if pba != -1:
            mvs.append((i, pba))
            pba = -1
        else:
            pba = i

if pab != -1:
    mvs.append((pab,pab))
    mvs.append((pab,pba))

print(len(mvs))
for a, b in mvs:
    print(a + 1, b + 1)
