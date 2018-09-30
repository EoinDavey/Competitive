import math
a,b,t,x = map(float,raw_input().split())
arm,mr = map(float,raw_input().split())
print int(math.floor(a*x*(100.0/(100.0+arm)) + b*x*(100.0/(100.0+mr)) + t*x))
