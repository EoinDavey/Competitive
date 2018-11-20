n, k = map(int ,raw_input().split())
s = raw_input()

op = []
out = []
for i in xrange(n):
    if len(out) >= k:
        break
    if s[i] == '(':
        op.append(i)
    else:
        if len(op):
            out.append(op[-1])
            out.append(i)
            op.pop()
st = set(out)
o = ""
for i in xrange(n):
    if i in st:
        o+=s[i]
print o
