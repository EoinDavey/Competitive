#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX_N= 44;
const int MX_XY = 808;
ll memo[MX_N][MX_XY][MX_XY];
int N;
int x[MX_N],y[MX_N];

ll dp(int p, int xS, int yS){
    if(p==N)
        return xS==0&&yS==0;
    if(memo[p][402+xS][402+yS] != -1)
        return memo[p][402+xS][402+yS];
    return memo[p][402+xS][402+yS] = dp(p+1,xS,yS) + dp(p+1,xS+x[p],yS+y[p]);
}

int main(){
    memset(memo,-1,sizeof(memo));
    scanf("%d",&N);
    for(int i = 0; i < N; ++i)
        scanf("%d %d",&x[i],&y[i]);
    printf("%lld\n",dp(0,0,0)-1LL);
    return 0;
}
