import sys

ls = [line for line in sys.stdin]

m = max(map(len,ls))
ls = ls[:-1]
sm = 0
for l in ls:
    sm+= (m - len(l))**2
print sm
