import sys
vowels = {'a','e','i','o','u','y'}
def toPig(s):
    if s[0] in vowels:
        return s + "yay"
    for i in xrange(len(s)):
        if s[i] in vowels:
            return s[i:] + s[:i] + "ay"
for line in sys.stdin:
    line=line.split()
    print " ".join(map(toPig,line))
