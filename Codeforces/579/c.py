from functools import reduce

def gcd(a,b):
    while b != 0:
        a, b = b, a % b
    return a

def divisors(x):
    c = 1
    cnt = 0
    while c*c <= x:
        if x%c == 0:
            cnt += 2 if c*c != x else 1
        c+=1
    return cnt

n = int(input())
a = [int(x) for x in input().split()]
g = reduce(lambda a, b: gcd(a,b), a)
print(divisors(g))
