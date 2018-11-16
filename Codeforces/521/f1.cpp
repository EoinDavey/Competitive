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
int N,K,X,a[MX_N], memo[MX_N][MX_N];
const int INF = 1000*1000*1000;

int dp(int p, int k){
    int mx = 0;
    if(k==0){
        return p < K-1 ? 0 : -INF;
    }
    if(p <= 0)
        return k==0 ? 0 : -INF;
    for(int i = 0; i < K && p-i >= 0; ++i)
        mx = max(mx, dp(p-i-1, k-1) + a[p-i]);
    return mx;
}

int main(){
    scanf("%d %d %d", &N, &K, &X);
    for(int i = 0; i < N; ++i){
        scanf("%d", a+i);
    }
    printf("%d\n", dp(N-1, X));
    return 0;
}
