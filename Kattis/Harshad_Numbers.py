def check(x):
    s = sum(map(lambda x: ord(x)-ord('0'), str(x)))
    return x%s==0

n = input()
while 1:
    if check(n):
        print n
        break
    n+=1
