import sys
from collections import defaultdict

def lines():
  return [line.strip() for line in sys.stdin]

INP = [(lambda x: (x[0][:-1], x[1:]))(ln.split(' ')) for ln in lines()]
ADJ_LIST = defaultdict(list, {a: b for a, b in INP})

def paths_between(s, t):
  memo = dict()
  def f(u):
    if u == t:
      return 1
    if u in memo:
      return memo[u]
    ans = sum(f(v) for v in ADJ_LIST[u])
    memo[u] = ans
    return ans
  return f(s)

def partA():
  return paths_between('you', 'out')

def partB():
  return (paths_between('svr', 'fft') * paths_between('fft', 'dac') * paths_between('dac', 'out')
    + paths_between('svr', 'dac') * paths_between('dac', 'fft') * paths_between('fft', 'out'))

print(f'Part A: {partA()}')
print(f'Part B: {partB()}')
