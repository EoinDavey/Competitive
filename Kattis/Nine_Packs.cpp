#include<bits/stdc++.h>
using namespace std;
constexpr int MX_HB = 101, MX_CNT=100001, INF=2000;

int H,B;
int h[MX_HB],b[MX_HB];
int hmemo[MX_HB][MX_CNT];
int bmemo[MX_HB][MX_CNT];

int dp(int u, int sm, int memo[][MX_CNT], int a[]){
    if(u==-1 || sm <= 0)
        return sm==0 ? 0 : INF;
    if(memo[u][sm] != -1)
        return memo[u][sm];
    return memo[u][sm] = min(1 + dp(u-1, sm-a[u],memo,a),dp(u-1,sm,memo,a));
}

int main(){
    scanf("%d",&H);
    for(int i = 0; i < H; ++i)
        scanf("%d",&h[i]);
    scanf("%d",&B);
    for(int i = 0; i < B; ++i)
        scanf("%d",&b[i]);
    memset(hmemo,-1,sizeof(hmemo));
    memset(bmemo,-1,sizeof(bmemo));
    int mn = INF;
    for(int i = 1; i < MX_CNT; ++i)
        mn=min(mn, dp(H-1,i,hmemo,h) + dp(B-1,i,bmemo,b));
    if(mn >= INF)
        puts("impossible");
    else
        printf("%d\n",mn);
    return 0;
}
