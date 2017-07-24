mx = 0
for a in range(100):
    for b in range(100):
        mx = max(mx, sum(map(lambda x: ord(x)-ord('0'),str(a**b))))
print mx
