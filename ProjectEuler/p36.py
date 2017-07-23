s = 0

def check(i):
    b = "{0:b}".format(i)
    return str(i) == str(i)[::-1] and b == b[::-1]

for i in range(1000000):
    if check(i):
        s+=i
print s
