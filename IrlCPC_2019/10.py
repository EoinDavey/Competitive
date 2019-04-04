from collections import defaultdict
N = int(input())
mp = defaultdict(int)
at = "@ucc.ie"
for _ in range(N):
    name = input()
    nN = ""
    for c in name:
        if c==' ':
            nN += '.'
        elif c >= 'A' and c <= 'Z':
            nN += chr(ord(c) - ord('A') + ord('a'))
        elif c >= 'a' and c <= 'z':
            nN += c
    mp[nN]+= 1
    ind = mp[nN]
    if ind > 1:
        nN+=str(ind)
    print(nN + at)

