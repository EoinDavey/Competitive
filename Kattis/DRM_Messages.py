s = raw_input()
a = s[:len(s)/2]
b = s[len(s)/2:]

def rot(xs):
    r = sum(map(ord,xs)) - ord('A')*len(xs)
    return map(lambda x: chr((ord(x)-ord('A')+r)%26 + ord('A')),xs)
a = rot(a)
b = rot(b)
print "".join(map(lambda x: chr((ord(a[x])-2*ord('A')+ord(b[x]))%26 + ord('A')),range(len(a))))
