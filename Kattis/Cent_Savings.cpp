#include<bits/stdc++.h>
using namespace std;

constexpr int MX_N=2002,MX_D=22,INF=1000000000;
int p[MX_N];
int N,D;
int memo[MX_N][MX_D];
int stab[MX_N];

int res(int u){
    if(u%10 >= 5)
        return ((u/10)+1)*10;
    return (u/10)*10;
}

int sm(int l, int r){
    return res(stab[r] - (l > 0 ? stab[l-1] : 0));
}

int dp(int u, int d){
    if(memo[u][d] != -1)
        return memo[u][d];
    if(d==0)
        return memo[u][d] = res(sm(0,u));
    int mn = INF;
    for(int i = 0; i < u; ++i)
        mn = min(mn,dp(i,d-1) + sm(i+1,u));
    return memo[u][d] = mn;
}

int main(){
    scanf("%d %d",&N,&D);
    for(int i = 0; i < N; ++i){
        scanf("%d",&p[i]);
        stab[i] = p[i] + (i > 0 ? stab[i-1] : 0);
    }
    memset(memo,-1,sizeof(memo));
    int mn = INF;
    for(int i = 0; i <= D; ++i)
        mn = min(mn, dp(N-1,i));
    printf("%d\n",mn);
    return 0;
}
