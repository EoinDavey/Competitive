n, S = map(int, raw_input().split())
cnt = 0
cnt += S/n
S = S%n
if S:
    cnt+=1
print cnt
