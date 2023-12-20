from collections import Counter
for _ in range(int(input())):
  input()
  xs = [int(x) for x in input().split()]
  c = Counter(xs)
  mx = 0
  for v in c.values():
    if (len(c) - 1) >= v:
      mx = max(mx, v)
    mx = max(mx, min(len(c), v-1))
  print(mx)
