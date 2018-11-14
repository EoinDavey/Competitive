import sys, math
x = input()
if x%2:
    i = 2
    while i*i <=x and x%i:
        i+=1
    if i*i <= x:
        print 1 + (x-i)/2
    else:
        print 1
else:
    print x/2
