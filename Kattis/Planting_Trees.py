N = int(raw_input())
xs = map(int,raw_input().split())
xs.sort(reverse=True)
d = 1
mx = 0
for x in xs:
    if d+x > mx:
        mx = d+x
    d+=1
print mx+1
