s = raw_input()
B = b = s[0]=='U'
s = s[1:]

cnt = 0
for c in s:
    w = c=='U'
    if w!=b:
        cnt+=1
        b=w
    if not b:
        cnt+=1
    b=True
print cnt

b=B
cnt = 0
for c in s:
    w = c=='U'
    if w!=b:
        cnt+=1
        b=w
    if b:
        cnt+=1
    b=False
print cnt

b=B
cnt = 0
for c in s:
    w = c=='U'
    if w!=b:
        cnt+=1
        b=w
print cnt
