from collections import defaultdict

inp = input().split()
mol = inp[0]
k = int(inp[1])
out = input()

def breakup(s):
  x = 0
  cnt = defaultdict(int)
  while x < len(s):
    l = s[x]
    x += 1
    n = ""
    while x < len(s) and '0' <= s[x] <= '9':
      n += s[x]
      x += 1
    cnt[l] += 1 if n == "" else int(n)
  return cnt

molCnt = defaultdict(int, {l: k * c for (l, c) in breakup(mol).items()})
outCnt = breakup(out)

mn = 10**9
for (l, x) in outCnt.items():
  mn = min(mn, molCnt[l] // x)

print(mn)
