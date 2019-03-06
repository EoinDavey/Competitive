n = input()
ls = raw_input()

def tr(inp):
  tots = [ls.count(x) for x in inp]
  cnts = [0 for _ in xrange(len(inp))]

  strts = [0]*len(inp)
  for i in xrange(1,len(strts)):
    strts[i] = tots[i-1] + strts[i-1]
  ends = [strts[i] + tots[i] for i in xrange(len(inp))]

  for i in xrange(len(inp)):
    for j in xrange(strts[i],ends[i]):
      if ls[j] != inp[i]:
        cnts[i] += 1

  ends = map(lambda x: x%n, ends)
  strts = map(lambda x: x%n, strts)

  mn = n
  for _ in xrange(n+2):
    for i in xrange(len(inp)):
      if ls[strts[i]] != inp[i]:
        cnts[i] -= 1
      strts[i] = (strts[i] + 1)% n
      if ls[ends[i]] != inp[i]:
        cnts[i] += 1
      ends[i] = (ends[i] + 1)% n
    mn = min(mn, sum(cnts))
  return mn

print min(tr(['A','B','C']), tr(['A','C','B']))
