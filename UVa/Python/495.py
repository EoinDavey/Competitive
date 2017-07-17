import sys
fib = [0]*5005
a,b = 0,1

for i in range(5005):
    fib[i]=a
    a,b = b,a+b

input_str = sys.stdin.read()

for x in input_str.split():
    print("The Fibonacci number for %s is %d" % (x,fib[int(x)]))
