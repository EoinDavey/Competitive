a = [0]*30

for i in range(2,21):
    t = i
    p = [0]*30
    for j in range(2,i+1):
        while(t%j==0):
            t/=j
            p[j]+=1
    for j in range(2,i+1):
        if p[j] > a[j]:
            a[j]=p[j]

print a
out = 1
for j in range(2,22):
    out *= j ** a[j]
print out
