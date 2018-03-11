MX_N = 14;
MX_SZ = (1<<14);

memo = [[-1 for _ in range(MX_SZ)] for _ in range(MX_N)]
hands = [[0 for _ in range(4)] for _ in range(MX_N)]

mp = {
    'J': 11,
    'Q': 12,
    'K': 13,
    'A': 14
}

mb = {
    11: 'J',
    12: 'Q',
    13: 'K',
    14: 'A'
}

def conv(s):
    if s in mp: return mp[s]-2
    return int(s)-2

def vnco(s):
    if s+2 in mb: return mb[s+2]
    return str(s+2)

def dp(p, st):
	if p==N:
		return st == (1<<13)-1;
	if memo[p][st]!=-1:
		return memo[p][st];
	for i in range(4):
		if((st&(1<<hands[p][i]))==0):
			if(dp(p+1,st|(1<<hands[p][i]))):
				memo[p][st] = True
				return True
	memo[p][st] = False
	return False

def pr(p, st):
	if(p==N):
		return
	for i in range(4):
		if((st&(1<<hands[p][i]))==0):
			if(dp(p+1,st|(1<<hands[p][i]))):
				print(vnco(hands[p][i]),end="")
				if p!=N-1:
				 	print(" ",end="")
				pr(p+1,st|(1<<hands[p][i]));
				return

N = 13;
for i in range(N):
	tmp = input().split()
	for j in range(4):
		hands[i][j] = conv(tmp[j])
	hands[i].sort(reverse=True)
dp(0,0)
pr(0,0);
print()
