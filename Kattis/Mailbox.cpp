#include<bits/stdc++.h>
using namespace std;

constexpr int MX_K=11,MX_M=111,INF=100000000;
int K,M;
int memo[MX_K][MX_M][MX_M];

int solve(int k, int l, int r){
    if(l==r)
        return 0;
    if(k<=0)
        return INF;
    if(memo[k][l][r]!=-1)
        return memo[k][l][r];
    int ans = INF;
    for(int i = l+1; i <= r; ++i){
        int a = solve(k,i,r); // doesn't explode
        int b = solve(k-1,l,i-1); // explodes
        ans = min(ans,max(a,b)+i);
    }
    return memo[k][l][r] = ans;
}

int main(){
    memset(memo,-1,sizeof(memo));
    int N; scanf("%d",&N);
    while(N-->0){
        scanf("%d %d",&K,&M);
        printf("%d\n",solve(K,0,M));
    }
    return 0;
}
