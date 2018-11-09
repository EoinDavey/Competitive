#include<bits/stdc++.h>
using namespace std;
const int MX_N = 111;
const int MX_M = 20002;
int memo[MX_N][MX_M][4];
int a[MX_N];
int N, M;

void pr(int i){while(i-->0)putchar(' ');}
int dp(int x, int m, int skp){
    //pr(x);printf("dp(%d,%d,%d)\n",x,m,skp);
    if(memo[x][m][skp] != -1)
        return memo[x][m][skp];
    if(x >= N)
        return 0;
    if(skp > 0)
        return dp(x+1, m, skp-1);
    int mx = 0;
    int sz = min(m, a[x]); 
    mx = max(mx, sz + dp(x+1, (2*m)/3, 0));
    mx = max(mx, sz + dp(x+1, m, 1));
    mx = max(mx, sz + dp(x+1, M, 2));
    return memo[x][m][skp] = mx;
}

int main(){
    memset(memo, -1, sizeof(memo));
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i){
        scanf("%d",a+i);
    }
    int mx = 0;
    for(int  k = 0; k < N; ++k)
        mx = max(mx, dp(k,M,0));
    printf("%d\n", mx);
    return 0;
}
