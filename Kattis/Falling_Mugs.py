D = int(raw_input())

d = {}

fail = True
for i in range(0,100002):
    b = i**2
    a = b - D
    if a in d:
        print d[a], i
        fail = False
        break
    d[b] = i

if fail:
    print "impossible"
