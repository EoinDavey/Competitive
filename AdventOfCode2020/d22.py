import sys
from collections import deque

def lines():
  return [line.strip() for line in sys.stdin]

[p1, p2] = [[int(y) for y in x.split('\n')[1:]] for x in '\n'.join(lines()).split('\n\n')]

def shrinkTo(q, ln):
  while len(q) > ln:
    q.pop()
  return q

def play(q1, q2):
  seen = set()
  while q1 and q2:
    k = tuple(q1), tuple(q2)
    if k in seen:
      return 1
    seen.add(k)
    a, b = q1.popleft(), q2.popleft()
    if a <= len(q1) and b <= len(q2):
      wn = play(shrinkTo(q1.copy(), a), shrinkTo(q2.copy(), b))
    else:
      wn = 1 if a > b else 0

    if wn:
      q1.append(a)
      q1.append(b)
    else:
      q2.append(b)
      q2.append(a)

  return 1 if q1 else 0

def score(q):
  sm = 0
  i = 1
  while q:
    sm += q.pop() * i
    i += 1
  return sm

def partA():
  q1, q2 = deque(p1), deque(p2)
  while q1 and q2:
    a, b = q1.popleft(), q2.popleft()
    if a > b:
      q1.append(a)
      q1.append(b)
    else:
      q2.append(b)
      q2.append(a)
  print(score(q1 or q2))

def partB():
  q1, q2 = deque(p1), deque(p2)
  print(score(q1 if play(q1, q2) else q2))

partA()
partB()
