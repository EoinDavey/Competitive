w = set(raw_input())
r = set()
s = raw_input()

i = 0
for c in s:
  if c in w:
    r.add(c)
  else:
    i+=1
  if len(r) == len(w):
    break

if i < 10:
  print "WIN"
else:
  print "LOSE"
