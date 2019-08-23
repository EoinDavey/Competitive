s = raw_input()
o = ""
for (a, b) in zip(s, s[1:]):
    if a == '1' and b == '0':
        o += "1"
    else:
        o += "0"
o += "0"
print o
