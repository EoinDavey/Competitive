#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int INF = 1000000;
const int MX_N = 222;
int a[MX_N][2];
int memo[MX_N][MX_N][4];
int N,K;

int dp(int k, int rem, int pst){
    if(memo[k][rem][pst]!=-1)
        return memo[k][rem][pst];
    int mx = a[k][0] + a[k][1] + dp(k+1,rem,0);
    if(k==N)
        return memo[k][rem][pst] = (rem == 0 ? 0 : -INF); 
    if(rem > 0 && pst!=2)
        mx = max(mx,a[k][1] + dp(k+1,rem-1,1));
    if(rem > 0 && pst!=1)
        mx = max(mx, a[k][0] + dp(k+1,rem-1,2));
    return memo[k][rem][pst] = mx;
}

int main(){
    while(scanf("%d %d",&N,&K),N||K){
        for(int i = 0; i < N; i++)
            scanf("%d %d",&a[i][0],&a[i][1]);
        memset(memo,-1,sizeof(memo));
        printf("%d\n",dp(0,K,0));
    }
    return 0;
}
