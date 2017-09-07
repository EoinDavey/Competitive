cnt = 1
while(True):
    N = int(raw_input())
    if N==0:
        break
    print "SET %d" % cnt
    cnt+=1
    ls = [[],[]]
    ind = 0
    for _ in range(N):
        ls[ind].append(raw_input())
        ind = 1-ind
    print "\n".join(ls[0])
    print "\n".join(ls[1][::-1])
