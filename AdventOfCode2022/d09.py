import sys

def lines():
  return [line.strip().split() for line in sys.stdin]
INP=[(d, int(t)) for (d, t) in lines()]

mvs = {
  'U': (0, 1),
  'D': (0, -1),
  'L': (-1, 0),
  'R': (1, 0)
}

def isAdj(T, H):
  return max(abs(T[0]-H[0]), abs(T[1]-H[1])) <= 1

def sgn(x):
  return x//abs(x) if x != 0 else 0


def sim(L):
  s = (0,0)
  R = [s]*L
  vis = set()
  vis.add(R[-1])

  for (d, t) in INP:
    dx, dy = mvs[d]
    for _ in range(t):
      R[0] = (R[0][0] + dx, R[0][1] + dy)
      for i in range(1, len(R)):
        if isAdj(R[i], R[i-1]):
          continue

        dtx = sgn(R[i-1][0] - R[i][0])
        dty = sgn(R[i-1][1] - R[i][1])
        R[i] = (R[i][0]+dtx, R[i][1]+dty)

        assert(isAdj(R[i], R[i-1]))
      vis.add(R[-1])

  print(len(vis))

def partA():
  sim(2)

def partB():
  sim(10)

partA()
partB()
