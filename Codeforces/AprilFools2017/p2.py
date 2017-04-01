n = hex(int(input()))
oneloops = ['a','d','h','o','p','q','r','0','4','6','9']
twoloops = ['b','8']
tot = -1
for i in n:
    if i in oneloops:
        tot+=1
    elif i in twoloops:
        tot+=2
print tot
