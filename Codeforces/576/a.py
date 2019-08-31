n, x, y = *map(int,input().split()),
a = *map(int,input().split()),
def check(i):
    return all(map(lambda x: x > a[i], a[max(0, i-x):i] + a[i+1:i+y+1]))

for i in range(n):
    if check(i):
        print(i+1)
        break
