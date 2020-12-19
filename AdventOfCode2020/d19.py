import sys
from functools import partial

def lines():
  return [line.strip() for line in sys.stdin]

def createSeqFn(s):
  return lambda e, i: seq(e, i, [rules[id] for id in s])

def createMatchFn(matches):
  return partial(choice, rls=[createSeqFn(x) for x in matches])

def consume(expr, idx, lit):
  if idx < len(expr) and expr[idx] == lit:
    return {idx + 1}
  return set()

def seq(expr, sidx, rls):
  st = {sidx}
  for rl in rls:
    idxs = set()
    for idx in st:
      idxs |= rl(expr, idx)
    st = idxs
  return st

def choice(expr, idx, rls):
  return set().union(*[rl(expr, idx) for rl in rls])

[rls, inputs] = [x.split('\n') for x in '\n'.join(lines()).split('\n\n')]

rules = {}

for rule in rls:
  [id, rule] = rule.split(': ')

  if rule[0] == '"':
    rules[id] = partial(consume, lit=rule[1])
    continue

  matches = [x.split(' ') for x in rule.split(' | ')]
  rules[id] = partial(choice, rls=[createSeqFn(x) for x in matches])

def partA():
  print(sum([len(line) in rules['0'](line, 0) for line in inputs]))

def partB():
  rules['8'] = createMatchFn([['42'], ['42', '8']])
  rules['11'] = createMatchFn([['42', '31'], ['42', '11', '31']])
  print(sum([len(line) in rules['0'](line, 0) for line in inputs]))

partA()
partB()
