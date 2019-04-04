import sys
cnt = 0
for line in sys.stdin:
    l = line.strip().split()
    l = map(lambda x: ''.join(sorted(x)), l)
    if len(set(l)) == len(l):
        cnt+=1
print cnt
