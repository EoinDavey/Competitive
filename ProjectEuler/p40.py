n = 1
s= ""
while(len(s) < 1000000):
    s+=str(n)
    n+=1

out = 1
for i in [1,10,100,1000,10000,100000,1000000]:
    out*=(ord(s[i-1])-ord('0'))
print out
