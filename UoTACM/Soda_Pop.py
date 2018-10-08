e,f,c = map(int, raw_input().split())
empties = e+f
tot = 0
while empties >= c:
    empties -= c
    tot+=1
    empties += 1
print tot
