import math
[A,I] = map(int, raw_input().split())

i = 0
while(True):
    if(math.ceil(i*1.0/A)==I):
        print i
        break
    i+=1
