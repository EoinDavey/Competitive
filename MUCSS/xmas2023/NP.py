input()
xs = [int(x) for x in input().split()]
es = [x for x in xs if x % 2 == 0]
os = [x for x in xs if x % 2 == 1]
es.sort()
os.sort()
if min(os) < min(es):
  print(' '.join(str(x) for x in os + es))
else:
  print(' '.join(str(x) for x in es + os))
