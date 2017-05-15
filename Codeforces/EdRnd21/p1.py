import math
n = int(raw_input())
l = math.floor(math.log(n+1 if n%10==0 else n,10))
base = pow(10,l)
ans = base - (n%base)
print "%.0f" % ans
