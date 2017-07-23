inp = map(lambda x: x[1:len(x)-1], raw_input().split(","))

s = set()

n = 0
for i in range(1,50):
    n+=i
    s.add(n)

cnt = 0
for n in inp:
    t = 0
    for c in n:
        t+= ord(c) - ord('A') + 1
    if t in s:
        cnt+=1
print cnt
