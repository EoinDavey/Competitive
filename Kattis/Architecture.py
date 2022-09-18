R, C = [int(x) for x in input().split()]

rs = [int(x) for x in input().split()]
cs = [int(x) for x in input().split()]

if max(rs) != max(cs):
  print("impossible")
else:
  print("possible")
