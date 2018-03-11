ls = [12, 103, 150, 249, 495, 738, 1544, 1852, 1988, 2316, 4184, 5262, 5640, 8657, 9791, 9953, 11682, 14258, 21279, 21630]
cmin,cmax = map(int,raw_input().split())
cnt = 0
for i in ls:
    if i >= cmin and i <= cmax:
        cnt+=1
print cnt
