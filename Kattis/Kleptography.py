import itertools
n, m = map(int, raw_input().split())
key = map(lambda x: ord(x) - ord('a'), raw_input())

msg = map(lambda x: ord(x) - ord('a'), raw_input())

a = [0]*(m-n) + key

for i in range(m)[::-1]:
    d = (msg[i] - a[i]) % 26
    if i - n >= 0:
        a[i-n] = d

print ''.join(map(lambda x: chr(ord('a')+x), a))
