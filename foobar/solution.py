from collections import deque
def search():
    LIM = 100000
    dis = {}
    s = set([1])
    q = deque([1])
    dis[1] = 0
    while q:
        u = q.popleft()
        for v in [u*2, u+1, u-1]:
            if v <= 0 or v >= LIM or v in s:
                continue
            s.add(v)
            q.append(v)
            dis[v] = dis[u] + 1
    return dis

def greedy(x):
    t = 0
    while x != 1:
        if x%2==0:
            x/=2
        else:
            x = (x - 1) if x == 3 or x%4 == 1 else x + 1
        t+=1
    return t
