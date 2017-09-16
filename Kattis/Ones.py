import sys

for line in sys.stdin:
    n = int(line)
    s = (1%n)
    cnt = 1
    while(True):
        if s==0:
            print cnt
            break
        s = ((s*10)+1)%n
        cnt+=1
