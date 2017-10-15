n, p = map(int,raw_input().split())

x0 = (p*1.0)/(n+1)
x = 1
while(True):
    nx = x0 * ((x+1)*(n+x-p+1))/(x*(n+x+1))
    x+=1
    if nx < x0:
        print "%.9f" % x0
        break
    x0 = nx
