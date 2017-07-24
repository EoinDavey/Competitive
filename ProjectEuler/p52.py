def st(i):
    n = list(str(i))
    n.sort()
    return "".join(n)

def check(x):
    ns = [i*x for i in range(1,7)]
    ss = map(st,ns)
    return all(map(lambda x: x==ss[0],ss))

n = 1
a = 0
while(True):
    if check(n):
        a = n
        print n
        break
    n+=1

print [i*a for i in range(1,7)]
