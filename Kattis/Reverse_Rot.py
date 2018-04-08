import sys
def ind(x):
    if x=='_':
        return 26
    if x=='.':
        return 27
    return ord(x)-ord('A')
ls = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_."
N = len(ls)

for line in sys.stdin:
    line = line.split()
    n = int(line[0])
    if n==0:
        break
    s = line[1]
    print "".join(reversed(map(lambda x: ls[(ind(x) + n)%N],s)))
