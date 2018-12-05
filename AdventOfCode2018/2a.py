from collections import Counter
import sys

ex2 = 0
ex3 = 0
for line in sys.stdin:
    l = list(line)
    for x in l:
        if l.count(x)==2:
            ex2+=1
            break
    for x in l:
        if l.count(x)==3:
            ex3+=1
            break
print ex2*ex3
