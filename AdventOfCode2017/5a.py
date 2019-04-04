import sys

jumps = [int(line.strip()) for line in sys.stdin]

i = 0
cnt = 0
while True:
    ni = i+jumps[i]
    if(jumps[i] >= 3):
        jumps[i]-=1
    else:
        jumps[i]+=1
    i = ni
    cnt +=1
    if i < 0 or i >= len(jumps):
        print cnt
        break
