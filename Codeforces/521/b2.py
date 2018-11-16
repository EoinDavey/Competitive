n = input()
flts = map(int, raw_input().split())

def dist(flts):
    for i in xrange(1, n-1):
        if flts[i]==0 and flts[i-1] == 1 and flts[i+1] == 1:
            return True
    return False

k = 0
while dist(flts):
    k+=1
    cnt = [0]*n
    for i in xrange(1, n-1):
        if flts[i]==0 and flts[i-1] == 1 and flts[i+1] == 1:
            cnt[i-1]+=1
            cnt[i+1]+=1
    ind = max(range(n), key=lambda x: cnt[x])
    flts[ind] = 0
print k
