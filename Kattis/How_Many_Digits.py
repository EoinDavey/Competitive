import math
import sys
N = 1000001
ln=[1]*N
sum = 0.0
for i in range(1,N):
    sum+=math.log10(i)
    ln[i] = int(1+math.floor(sum))

for line in sys.stdin:
    print ln[int(line)]
