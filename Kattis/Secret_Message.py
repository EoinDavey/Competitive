N = int(raw_input())

for _ in range(N):
    ms = raw_input()
    k = 0

    for i in range(1000):
        if i*i >= len(ms):
            k=i
            break

    og = [['*']*k for _ in range(k)]

    idx=idy = 0
    for l in ms:
        og[idx][idy]=l
        idy+=1
        if idy>=k:
            idy%=k
            idx+=1
    new = zip(*og[::-1])

    print "".join([c if c!='*' else "" for l in new for c in l])
