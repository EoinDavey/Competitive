import fileinput
s = set()

def proc(x):
    global s
    l = x.lower()
    if l in s:
        return '.'
    s.add(l)
    return x

for line in fileinput.input():
    print " ".join([proc(w) for w in line.split()])
