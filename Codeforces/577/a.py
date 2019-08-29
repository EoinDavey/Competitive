from collections import Counter
from functools import reduce

n, m = [int(x) for x in input().split()]
scrs = [input() for _ in range(n)]
a = [int(x) for x in input().split()]
cnts = [Counter([x[i] for x in scrs]).most_common(1)[0][1] for i in range(m)]
print(reduce(lambda x, y: x + y[0]*y[1], zip(cnts, a), 0))
