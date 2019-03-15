from collections import defaultdict
s = raw_input()
t = raw_input()
chrs = set(t)

nxt = defaultdict(lambda:  -1)

jmp = [{} for _ in xrange(len(s))]

for i in xrange(len(s)-1, -1, -1):
  for c in chrs:
    jmp[i][c] = nxt[c]
  nxt[s[i]] = i

tot = 0

def wlk(x):
  if s[i] == t[0]:
    for c in t[1:]:
      x = jmp[x][c]
      if x==-1:
        break
    return x
  for c in t:
    x = jmp[x][c]
    if x==-1:
      break
  return x

for i in xrange(len(s)):
  j = wlk(i)
  if j==-1:
    continue
  tot+=len(s) -  j

print tot
