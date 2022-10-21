h, w = [int(x) for x in input().split()]

l = ""
sm = 0
total = 0
for _ in range(h):
  l = input()
  for i in range(w):
    if l[i] == '.':
      continue
    sm += i
    total += 1

lft = 0
for i in range(w):
  if l[i] != '.':
    lft = i - 0.5
    break

rght = 0
for i in range(w):
  if l[i] != '.':
    rght = i + 0.5

if sm < lft * total:
  print("left")
elif sm > rght * total:
  print("right")
else:
  print("balanced")
