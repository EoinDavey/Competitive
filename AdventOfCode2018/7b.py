import sys
from heapq import heappush, heappop
from collections import defaultdict

NUM_WORKERS = 5

def cost(x):
    return 60+1+ord(x)-ord('A')

# default dict is the same as a dict, but defaults to 0 and [] for ints and lists
indeg = defaultdict(int)
adjList = defaultdict(list)
letters = set()

for line in sys.stdin:
    l = line.strip().split()

    u, v = l[1], l[7]

    indeg[v] +=1

    adjList[u].append(v)

    letters.add(u)
    letters.add(v)

readyQ = [] #priority queue for available tasks
workQ = [] #priority queue for current busy workers

for x in letters: # Add all the starter jobs
    if indeg[x] == 0:
        heappush(readyQ, x)

# loop over every second
time = 0
while readyQ or workQ: # we have jobs to do, or are currently working

    # loop over completed jobs in the queue
    while workQ and workQ[0][0] <= time: 
        job = heappop(workQ)[1]

        # same operation as part 1, reduce indegree of neigbhours by 1, if its 0 add to readyQ
        for v in adjList[job]:
            indeg[v]-=1
            if indeg[v]==0:
                heappush(readyQ, v)

    # loop over jobs we can do, only doing at most NUM_WORKERS jobs at a time

    while readyQ and len(workQ) < NUM_WORKERS:
        x = heappop(readyQ)
        heappush(workQ, (time+cost(x), x))

    time+=1

print time-1
