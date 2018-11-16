n = input()
flts = map(int, raw_input().split())

tot = 0
for i in xrange(n):
    if flts[i] == 0:
        continue
    st = i
    j = i
    while j < n-1 and flts[j+1] != flts[j]:
        j+=1
    if flts[j] == 0:
        j-=1
    for k in xrange(i, j+1):
        flts[k] = 0
    ln = j-st + 1 
    print st, ln
    tot += max(0, (ln/2) - 1)
print tot
