s = set()

def gcd(a,b):
    if b == 0:
        return a
    return gcd(b, a%b)

def reduce(i,j):
    g = gcd(i,j)
    return (i/g,j/g)

def check(i,j):
    r = reduce(i,j)
    si = list(str(i))
    sj = list(str(j))
    for n in si:
        if n in sj:
            si.remove(n)
            sj.remove(n)
        if n == '0':
            return False
    if len(si)==2:
        return False
    new = reduce(ord(si[0])-ord('0'),ord(sj[0])-ord('0'))
    return new == r



def run():
    for i in range(11,100):
        for j in range(i+1,100):
            if check(i,j):
                s.add((i,j))
run()
n = d = 1
for (x,y) in s:
    n*=x
    d*=y
(_,nd) = reduce(n,d)
print nd
