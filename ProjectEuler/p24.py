a = 0
b = 1
cnt = 1
while(True):
    a,b = b,a+b
    if len(str(a)) == 1000:
        print cnt
        break
    cnt+=1
