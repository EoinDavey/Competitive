import math
def sqrtx(x):
    R = math.floor(math.sqrt(x))
    if R*R==x:
        return 0
    a = R
    P = 0
    Q = 1
    cnt=0
    while(1):
        P = a*Q - P
        Q = (x - P*P)/Q
        a = math.floor((R+P)/Q)
        cnt+=1
        if Q==1:
            return cnt

tot = 0
for x in range(10001):
    if sqrtx(x)%2==1:
        tot+=1
print tot
