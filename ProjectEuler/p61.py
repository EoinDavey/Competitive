import itertools
def trigen():
    n = 1
    while(1):
        yield(n*(n+1)/2)
        n+=1
def sqgen():
    n = 1
    while(1):
        yield(n*n)
        n+=1
def pengen():
    n = 1
    while(1):
        yield(n*(3*n - 1)/2)
        n+=1
def hexgen():
    n = 1
    while(1):
        yield(n*(2*n - 1))
        n+=1
def hepgen():
    n = 1
    while(1):
        yield(n*(5*n-3)/2)
        n+=1
def octgen():
    n = 1
    while(1):
        yield(n*(3*n-2))
        n+=1

def cycles(x,y):
    return str(x)[2:] == str(y)[:2]

def fullcycles(xs):
    perms = itertools.permutations(xs)
    for p in perms:
        if all(map(lambda x: cycles(*x), zip(p,p[1:]+(p[0],)))):
            return True
    return False

def lcycles(xs):
    perms = itertools.permutations(xs)
    for p in perms:
        if all(map(lambda x: cycles(*x), zip(p,p[1:]))):
            return True
    return False

gens = [trigen,sqgen,pengen,hexgen,hepgen,octgen]

N = 10000

ngen = [filter(lambda x: x >= 1000 ,list(itertools.takewhile(lambda x: x < N, (n for n in gn())))) for gn in gens]

for a in ngen[0]:
    for b in ngen[1]:
        if not lcycles([a,b]):
            continue
        for c in ngen[2]:
            if not lcycles([a,b,c]):
                continue
            for d in ngen[3]:
                if not lcycles([a,b,c,d]):
                    continue
                for e in ngen[4]:
                    if not lcycles([a,b,c,d,e]):
                        continue
                    for f in ngen[5]:
                        if not fullcycles([a,b,c,d,e,f]):
                            continue
                        print a,b,c,d,e,f
                        print sum([a,b,c,d,e,f])
