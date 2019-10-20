import sys
import random
from collections import deque, defaultdict

indmp = defaultdict(list)

N = int(input())

st = set(range(1, 2*N+1))
q = deque()
nmatch = 0
while nmatch < 2*N:
    if q:
        a, b = q.pop()
        print(a,b)
        sys.stdout.flush()
        assert(input() == "MATCH")
        nmatch += 2
        continue

    x, y = st.pop(), st.pop()
    st.add(x)
    st.add(y)
    print(x,y)
    sys.stdout.flush()
    resp = input()

    if resp == "MATCH":
        nmatch += 2
        st.remove(x)
        st.remove(y)
        continue

    v1, v2 = [int(x) for x in resp.split()]
    indmp[v1].append(x)
    indmp[v2].append(y)

    while len(indmp[v1]) >= 2:
        x = indmp[v1].pop()
        y = indmp[v1].pop()
        q.append((x,y))
        st.remove(x)
        st.remove(y)

    while len(indmp[v2]) >= 2:
        x = indmp[v2].pop()
        y = indmp[v2].pop()
        q.append((x,y))
        st.remove(x)
        st.remove(y)
print(-1)
