import math
N = int(raw_input())

s = set()
lm = int(math.sqrt(N) + 2)

for i in range(1,lm):
    if N%i==0:
        s.add(i)
        s.add(N/i)
l = sorted(list(s))

print " ".join(map(lambda x: str(x-1),l))
