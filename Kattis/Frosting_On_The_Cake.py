n = input()
a = map(int,raw_input().split())
b = map(int,raw_input().split())

asms = [0,0,0]

for i in xrange(n):
    asms[i%3]+=a[i]

tot = [0,0,0]
ind = [2,0,1]

for i in xrange(n):
    for k in xrange(3):
        tot[ind[k]]+=b[i]*asms[k]
    ind = ind[1:] + ind[:1]
print ' '.join(map(str,tot))
