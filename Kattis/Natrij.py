[gh,gm,gs] = map(int, raw_input().split(':'))
[bh,bm,bs] = map(int, raw_input().split(':'))

def pr(x):
    return ("0" if (x < 10) else "")+ str(x)

s = bs - gs
m = bm - gm
h = bh - gh

if s < 0:
    s+=60
    m-=1

if m < 0:
    m+=60
    h-=1

if h < 0:
    h+=24

print ":".join(pr(x) for x in [h,m,s])
