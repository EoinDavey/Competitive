N = 10000

def pal(x):
    s = str(x)
    return s == s[::-1]

def nxt(x):
    return x + int(str(x)[::-1])

def check(x):
    for _ in range(52):
        x = nxt(x)
        if pal(x):
            return True
    return False

cnt = 0
for x in range(1,10000):
    if not check(x):
        cnt+=1

print cnt
