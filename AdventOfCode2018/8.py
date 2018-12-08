import sys

s = map(int, raw_input().split())

i = 0
def read():
    global i
    c = s[i]
    i+=1
    m = s[i]

    val = 0

    i+=1
    ch = [0]*c
    for j in xrange(c):
        ch[j] = read()
    for _ in xrange(m):
        x=s[i]
        if c:
            if x-1 < c:
                val+=ch[x-1]
        else:
            val+=x
        i+=1

    return val

print read()
