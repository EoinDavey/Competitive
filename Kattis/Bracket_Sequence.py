from functools import reduce
n = int(input())

MOD = 10**9 + 7

tkns = input().split()

st = [[]]
p = [True]
w = 0
while True:
  if w >= len(tkns):
    break
  if tkns[w] == ')':
    ret = st.pop()
    if p.pop():
      st[-1].append(reduce(lambda x, y: (x + y) % MOD, ret, 0))
    else:
      st[-1].append(reduce(lambda x, y: (x * y) % MOD, ret, 1))
    w += 1
    continue
  if tkns[w] == '(':
    st.append([])
    p.append(not p[-1])
    w += 1
    continue
  st[-1].append(int(tkns[w]))
  w += 1

tree = st[0]

print(reduce(lambda x, y: (x + y) % MOD, tree, 0))
