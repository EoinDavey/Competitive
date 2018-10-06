MD = 10**9 + 7
memo = [[[-1]*202 for _ in range(202)] for _ in range(404)]

def dp(l, r, k):
    if r < l:
        return pow(26, k/2, MD)
    if k==0:
        return 0
    if memo[l][r][k] != -1:
        return memo[l][r][k]
    if s[l] == s[r]:
        c = (dp(l+1, r-1, k-2) + ((25 * dp(l,r,k-2)) % MD)) % MD
        memo[l][r][k] = c
        return c
    c = (dp(l+1,r,k-2) + (dp(l,r-1,k-2) + ((24*dp(l,r,k-2))%MD))%MD)%MD
    memo[l][r][k] = c
    return c

N = input()
s = raw_input()
print dp(0,N-1,2*N)
