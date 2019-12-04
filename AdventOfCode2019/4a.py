def test(s):
    return len(s) == 6 and s == ''.join(sorted(s)) and any(map(lambda x: x[0] == x[1], zip(s, s[1:])))

cnt = 0
L, R = *map(int, input().split('-')),

for i in range(L, R+1):
    if test(str(i)):
        cnt+=1
print(cnt)
