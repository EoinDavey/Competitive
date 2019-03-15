from collections import defaultdict
VIS=1
EXP=2
INF=10**10
st = {}
mem={}
adjList = defaultdict(list)
def trav(u, d):
  if (u,d) in st and st[(u,d)] == EXP:
    return mem[(u,d)]
  st[(u,d)] = VIS
  if u == t:
    mem[(u,d)] = 0
    st[(u,d)] = EXP
    return 0
  ans = 0
  if d: # go as far as possible
    mx = 0
    for v, c in adjList[u]:
      if (v, not d) in st and st[(v, not d)] == VIS:
        mx = INF
      else:
        mx = max(mx, c + trav(v, not d))
    ans = mx
  else:
    mn = INF
    for v, c in adjList[u]:
      if (v, not d) not in st or st[(v, not d)] != VIS:
        mn = min(mn, c + trav(v, not d))
    ans = mn
  st[(u,d)] = EXP
  mem[(u,d)] = ans
  return ans

n,m,s,t = map(int, raw_input().split())

for _ in xrange(m):
  a,b,w = map(int, raw_input().split())
  adjList[a].append((b,w))

ans = trav(s, True)

if ans >= INF:
  print "infinity"
else:
  print ans
