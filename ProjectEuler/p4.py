l = []
for i in range(100,1000):
    for j in range(100,1000):
        a = i * j
        if str(a) == str(a)[::-1]:
           l.append(a)
print max(l)
