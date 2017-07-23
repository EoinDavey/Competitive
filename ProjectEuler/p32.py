pan = set()
s = set()
for i in range(1,9877):
    _dig = set()
    cnt = 0
    for n in str(i):
        _dig.add(n)
        cnt+=1
    if len(_dig) == cnt:
        pan.add(i)

def check(i,j):
    dig = [False]*10
    for n in str(i):
        if dig[ord(n)-ord('0')]:
            return False
        dig[ord(n)-ord('0')]=True
    for n in str(j):
        if dig[ord(n)-ord('0')]:
            return False
        dig[ord(n)-ord('0')]=True
    for n in str(i*j):
        if dig[ord(n)-ord('0')]:
            return False
        dig[ord(n)-ord('0')]=True
    return all(dig[1:]) and not dig[0]

for i in pan:
    for j in pan:
        if check(i,j):
            s.add(i*j)

print sum(s)

