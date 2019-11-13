from itertools import permutations

# building = (w, h)

# rec = (p, q) points
# point = (x, y)

INF = 10**100

def P(p):
    return p[0]

def Q(p):
    return p[1]

def X(p):
    return p[0]

def Y(p):
    return p[1]

def height(b):
    return b[1]

def width(b):
    return b[0]

def rectIntst(a, b):
    if X(P(a)) > X(Q(b)) or Y(P(a)) > Y(Q(b)) or X(P(b)) > X(Q(a)) or X(P(a)) or Y(P(b)) > Y(Q(a)):
        return None
    p = (max(X(P(a)), X(P(b))), max(Y(P(a)), Y(P(b))))
    q = (min(X(Q(a)), X(Q(b))), min(Y(Q(a)), Y(Q(b))))
    return (p, q)

def bndBox(blds):
    stckA = sum(map(height, blds)) * max(map(width, blds))
    rowA = sum(map(width, blds)) * max(map(height, blds))
    mn = min(stckA, rowA)

    A,B,C = blds
    Arec = ((0, 0), (width(A)-1, height(A)-1))
    Brec = ((0, height(A)), (width(B)-1, height(A) + height(B) - 1))
    Crec = ((width(A), 0), (width(A) + width(C)-1, height(C) - 1))


    if rectIntst(Brec, Crec) == None:
        h = max(height(A) + height(B), height(C))
        w = max(width(A) + width(C), width(B))
        mn = min(mn, h*w)

    return mn

for _ in range(int(input())):
    a1, b1, a2, b2, a3, b3 = *map(int, input().split()),
    mn = 10**100
    for perm in permutations([(a1, b1), (a2, b2), (a3, b3)]):
        for i in range(1 << 3):
            ls = list(perm)
            for j in range(3):
                if (i & (1<<j)) != 0:
                    ls[j] = (ls[j][1], ls[j][0])
            mn = min(mn, bndBox(ls))
    print(mn)
