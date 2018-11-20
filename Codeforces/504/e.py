from sys import stdout
n = input()

p = (n,n)
ans1 = []
ans2 = []
while p[0] + p[1] > n+1:
    print "?", 1, 1, p[0]-1, p[1]
    stdout.flush()
    rsp = raw_input()
    if rsp == "YES":
        p = (p[0]-1,p[1])
        ans2.append('D')
    else:
        p = (p[0],p[1]-1)
        ans2.append('R')

ans2 = ans2[::-1]

p = (1,1)
while p[0]+p[1] < n+1:
    print "?", p[0], p[1]+1,  n, n
    stdout.flush()
    rsp = raw_input()
    if rsp == "YES":
        p = (p[0],p[1]+1)
        ans1.append('R')
    else:
        p = (p[0]+1,p[1])
        ans1.append('D')

print "!", ''.join(ans1+ans2)
