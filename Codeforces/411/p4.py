inp = raw_input()
n = len(inp)
tot = [0]*n
mod = pow(10,9) + 7
modifier = 0
for i in range(n-1,-1,-1):
    if inp[i] == 'b':
        tot[i]+=1
    if i != n-1:
        tot[i] += tot[i+1]
rSum = 0
for i in range(n-1,-1,-1):
    if inp[i] == 'a':
        rSum*=2
        rSum+=tot[i]
        rSum = rSum % mod
print rSum % mod
