solved = {}

count = {}

while(True):
    s = raw_input()
    if s=="-1":
        break
    [a,b,c] = s.split()
    a = int(a)
    if c=="right":
        solved[b] = True
        if b in count:
            count[b] += a
        else:
            count[b] = a
    else:
        if b in count:
            count[b] += 20 
        else:
            count[b] = 20 

sm = 0
for k in solved.keys():
    sm+=count[k]

print len(solved), sm
