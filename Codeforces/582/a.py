def inp(): return int(input())
def ln(): return [int(x) for x in input().split()]

n = inp()
x = ln()

mn = 10**20
for i in range(n):
    # here
    cst = 0
    for c in x:
        cst += 1 if abs(c-x[i]) % 2  == 1 else 0
    mn = min(mn, cst)
print(mn)
