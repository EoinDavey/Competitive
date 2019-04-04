def bsub(n):
    if n[0] != 'B':
        return "bo-b"+n[1:]
    return "bo-"+n[1:]
def fsub(n):
    if n[0] != 'F':
        return "fo-f"+n[1:]
    return "fo-"+n[1:]
def msub(n):
    if n[0] != 'M':
        return "mo-m"+n[1:]
    return "mo-"+n[1:]

name = input()

print(', '.join([name, name, bsub(name)]))
print(', '.join(["bo-na-na fanna", fsub(name)]))
print(', '.join([("fee fi %s" % msub(name)), name+"!"]))
