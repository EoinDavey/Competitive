import sys
ls = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"
L = len(ls)
def cor(c):
    for i in xrange(L):
        if ls[i]==c:
            return ls[i-1]

def fixWord(xs):
    return "".join((map(cor,xs)))

for line in sys.stdin:
    line = line.split()
    print " ".join(map(fixWord,line))
