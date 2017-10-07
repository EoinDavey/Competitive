N = input()

rrs = [raw_input().split()for _ in range(N)]
rrs = map(lambda x: [x[0],float(x[1]),float(x[2])],rrs)
rrs = sorted(rrs,key=lambda x:x[2])

bsttm = 100000
ans = []
for i in xrange(len(rrs)):
    rst = rrs[:i] + rrs[i+1:]
    tm = rrs[i][1] + sum(map(lambda x:x[2],rst[:3]))
    if tm < bsttm:
        bsttm = tm
        ans = [rrs[i][0]] + map(lambda x:x[0],rst[:3])

print bsttm
print "\n".join(ans)
