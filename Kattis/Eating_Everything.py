from collections import defaultdict

n, m = [int(x) for x in input().split()]
cs = [int(x) for x in input().split()]

adjList = defaultdict(list)

for _ in range(m):
  s, t = [int(x) for x in input().split()]
  adjList[s].append(t)


memo = {}
def explore(u):
  if u in memo:
    return memo[u]
  mx = cs[u]
  for v in adjList[u]:
    # Choose
    mx = max(mx, cs[u] + 0.5 * explore(v))
    # Don't
    mx = max(mx, explore(v))

  memo[u] = mx
  return mx

print(explore(0))
