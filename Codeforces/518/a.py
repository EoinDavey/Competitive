import math
N,M,K,L = map(int,raw_input().split())

lb = L+K
x = lb/M if lb%M==0 else lb/M + 1

if x*M <= N:
    print x
else:
    print -1
