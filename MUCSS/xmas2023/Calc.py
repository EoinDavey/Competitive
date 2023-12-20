EPS = 1e-6
def f(x, b):
  return pow(x, x*b + 1) * (2-x)

def trn(b):
  l, u = EPS, 2-EPS
  while abs(u-l) > EPS:
    x = l + (u-l)/3
    y = l + 2*(u-l)/3
    fx = f(x, b)
    fy = f(y, b)
    if fx < fy:
      l = x
    else:
      u = y
  return f(u, b)

for _ in range(int(input())):
  b = float(input())
  print(trn(b))
