import sys
[x,y,N] = map(int,raw_input().split())
for i in range(1,N+1):
    if i % x ==0:
        sys.stdout.write("Fizz")
    if i %y==0:
        sys.stdout.write("Buzz")
    if i%x!=0 and i %y!=0:
        sys.stdout.write(str(i))
    print
