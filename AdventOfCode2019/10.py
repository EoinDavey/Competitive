import sys
from math import gcd, atan2
from itertools import zip_longest, chain, islice, groupby
board = list(map(lambda x: x.strip(), sys.stdin))
H = len(board)
W = len(board[0])

def a():
    return max([(len(set([(lambda g: ((a-x)//g, (b-y)//g))(gcd(a-x,b-y)) for a in range(len(board)) for b in range(W) if (a,b) != (x,y) and board[a][b] == '#'])), x, y) for x in range(len(board)) for y in range(W) if board[x][y] == '#'])

def b(ax, ay):
    return (lambda pt: pt[1]*100 + pt[0])((lambda sf: next(islice(filter(lambda x: x, chain.from_iterable(zip_longest(*map(lambda x: list(x[1]), groupby(sorted([(a,b) for a in range(H) for b in range(W) if (a!=ax or b != ay) and board[a][b] == '#'], key=sf), key=sf))))), 199, None)))(lambda x: (lambda g: (lambda h: atan2(-h[1], h[0]))(((x[0]-ax)/g, (x[1]-ay)/g)))(gcd(x[0]-ax, x[1]-ay))))

amx, ax, ay = a()
print('Part A', amx)
print('Part B', b(ax,ay))
