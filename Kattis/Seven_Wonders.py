S = raw_input()
cnt = {'T':0, 'G':0,'C':0};
for c in S:
    cnt[c]+=1

score = 0
mn = 100
for v in cnt.values():
    score += v**2
    mn = min(mn,v)
score += 7*mn
print score
