import sys
from heapq import heappush, heappop

indeg = {}
adjList = {}
letters = set()

for line in sys.stdin:
    l = line.strip().split()
    u, v = l[1], l[7]

    if v in indeg:
        indeg[v] +=1
    else:
        indeg[v] = 1

    if u in adjList:
        adjList[u].append(v)
    else:
        adjList[u] = [v]

    letters.add(u)
    letters.add(v)

pq = [] #priority queue

for x in letters:
    if x not in indeg or indeg[x] == 0:
        heappush(pq, x)

ans = ""
while pq:
    x = heappop(pq)
    ans += x

    if x in adjList:
        for v in adjList[x]:
            indeg[v]-=1
            if indeg[v]==0:
                heappush(pq, v)

print "".join(ans)
