names = map(lambda x: x[1:len(x)-1],raw_input().split(','))

names.sort()

tot = 0
for i,n in enumerate(names):
    t = 0
    for c in n:
        t+= ord(c)-ord('A')+1
    tot+=t*(i+1)

print tot
