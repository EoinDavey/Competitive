#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
typedef complex<double> cc;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int MX_N = 202;
int N,K,X;
ll a[MX_N], memo[MX_N][MX_N];
const ll INF = 1000LL*1000LL*1000LL * 100LL * 100LL;

ll dp(int p, int k){
    ll mx = -INF;
    if(k==0){
        return p < K ? 0 : -INF;
    }
    if(p <= 0)
        return k==0 ? 0 : -INF;
    if(memo[p][k] != -1)
        return memo[p][k];
    for(int i = 1; i <= K && p-i >= 0; ++i)
        mx = max(mx, dp(p-i, k-1) + a[p-i]);
    return memo[p][k] = mx;
}

int main(){
    memset(memo, -1, sizeof(memo));
    scanf("%d %d %d", &N, &K, &X);
    for(int i = 0; i < N; ++i){
        scanf("%lld", a+i);
    }
    ll ans = dp(N, X);
    if(ans < 0LL)
        puts("-1");
    else
        printf("%lld\n", dp(N, X));
    return 0;
}
