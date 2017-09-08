[D,M] = map(int,raw_input().split())

months = [0,31,28,31,30,31,30,31,31,30,31,30,31]
days = ["Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"]

dw = 3
d = 1
m = 1

while(1):
    if d==D and m == M:
        print days[dw%7]
        break
    d+=1
    if d>months[m]:
        d = 1
        m+=1
    dw+=1
