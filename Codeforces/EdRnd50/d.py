import sys
n = input()
a = map(int, raw_input().split())
m = input()
b = map(int, raw_input().split())

if(sum(a) != sum(b)):
    print -1
    sys.exit(0)

N = max(len(a), len(b))
asm = 0
bsm = 0
cnt = 0

while len(a) or len(b):
    if asm > bsm:
        bsm += b.pop()
    else:
        asm+= a.pop()
    if asm==bsm:
        asm=bsm=0
        cnt+=1
print cnt
