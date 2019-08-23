from sys import stdout
LOMASK = (2**7 - 1)
HIMASK = LOMASK << 7

f = [(x << 7 | LOMASK ) for x in range(100)]
s = [(HIMASK | x ) for x in range(100)]

print('?', ' '.join(map(str, f)))
stdout.flush()
lo = int(input())
print('?', ' '.join(map(str, s)))
stdout.flush()
hi = int(input())

ans = ((hi & HIMASK) ^ HIMASK) | ((lo & LOMASK) ^ LOMASK)
print("!", ans)
