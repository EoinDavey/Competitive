def sumdig(k):
    sm = 0
    while k>0:
        sm+=k%10
        k/=10
    return sm

while(True):
    n = int(raw_input())
    if n==0:
        break
    a = sumdig(n)
    i = 11
    while(True):
        if sumdig(n*i)==a:
            print i
            break
        i+=1
