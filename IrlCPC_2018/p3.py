f = []
l = int(input())
while l:
    if f: f.append(f.pop(0))
    f.append(l - 1)
    l -= 1
print(" ".join(map(str, f[::-1])))
