#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MD = 1000*1000*1000 + 7;
const int MX_N = 202;
ll memo[MX_N][MX_N][MX_N];
ll mpow[MX_N];

ll dp(int l, int r, int k, const string& s){
    if(r < l)
        return mpow[k/2];
    if(k==0)
        return 0;
    if(memo[l][r][k/2] != -1)
        return memo[l][r][k/2];
    if(s[l] == s[r])
        return memo[l][r][k/2] = (dp(l+1, r-1, k-2, s) + ((25 * dp(l,r,k-2, s)) % MD)) % MD;
    return memo[l][r][k/2] = (dp(l+1,r,k-2, s) + (dp(l,r-1,k-2, s) + ((24*dp(l,r,k-2, s))%MD))%MD)%MD;
}

int main(){
    memset(memo,-1,sizeof(memo));
    mpow[0] = 1LL;
    for(int i = 1; i < MX_N; ++i)
        mpow[i] = (mpow[i-1]*26LL) % MD;
    int N; cin >> N;
    string s; cin >> s;
    printf("%lld\n",dp(0,N-1,2*N, s));
    return 0;
}
