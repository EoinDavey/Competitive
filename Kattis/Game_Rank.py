sq = raw_input()

strs = [0,5,5,5,5,5,5,5,5,5,5,4,4,4,4,4,3,3,3,3,3,2,2,2,2,2]

cur=0
run=0
lvl = 25

lgnd = False

for c in sq:
    if c=='W':
        cur+=1
        run+=1
        if lvl >= 6 and run >= 3:
            cur+=1
        if cur > strs[lvl]:
            cur = cur - strs[lvl]
            lvl-=1
    else:
        run=0
        if lvl >= 1 and lvl <= 20:
            cur-=1
        if cur == -1:
            if lvl < 20:
                lvl+=1
                cur = strs[lvl]-1
            else:
                cur = 0
    if lvl==0:
        lgnd = True
        break

if lgnd:
    print "Legend"
else:
    print lvl
