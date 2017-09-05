vals = [{'A':11, 'K':4, 'Q':3, 'J':20, 'T':10, '9':14, '8':0, '7':0},
        {'A':11, 'K':4, 'Q':3, 'J':2, 'T':10, '9':0, '8':0, '7':0}]

[N,B] = raw_input().split()
N = int(N)
sm = 0
for _ in xrange(4*N):
  c = raw_input()
  if c[1] == B:
    sm += vals[0][c[0]]
  else:
    sm += vals[1][c[0]]

print sm
