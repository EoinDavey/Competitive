#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX_SD = 2222;
const ll INF = 1000000000000LL;
int N,T;
int D[MX_SD];
ll C[MX_SD],F[MX_SD],U[MX_SD],cst[MX_SD],memo[MX_SD][MX_SD];

ll dp(int u, int del){
    if(u==N)
        return del>=T ? 0LL : INF;
    if(memo[u][del]!=-1LL)
        return memo[u][del];
    return memo[u][del] = min(dp(u+1,del),cst[u]+dp(u+1,del+D[u]));
}

int main(){
    scanf("%d",&N);
    for(int i = 0; i < N; ++i)
        scanf("%d %lld %lld %lld",D+i,C+i,F+i,U+i);
    int totdel = 0;
    for(int i = 0; i < N; ++i){
        totdel+=D[i];
        ll tot = C[i]+F[i]+U[i];
        cst[i] = (2LL+F[i] + U[i] - C[i])/2LL;
        if(cst[i] > U[i])
            cst[i] = INF;
        cst[i] = max(0LL,cst[i]);
    }
    T = (2+totdel)/2;
    memset(memo,-1,sizeof(memo));
    ll ans = dp(0,0);
    if(ans >= INF)
        puts("impossible");
    else
        printf("%lld\n",ans);
    return 0;
}
