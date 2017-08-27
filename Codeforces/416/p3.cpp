#include<bits/stdc++.h>
using namespace std;

const int MX_N = 5005;
int N,a[MX_N],ls[MX_N],rs[MX_N];

int main(){
    scanf("%d",&N);
    memset(ls,-1,sizeof(ls));
    for(int i = 0; i < N; i++){
        scanf("%d",&a[i]);
        if(ls[a[i]]==-1)
            ls[a[i]]=i;
        rs[a[i]]=i;
    }
    int dp[N];
    memset(dp,0,sizeof(dp));
    bool vis[MX_N];
    for(int i = 0; i < N; i++){
        memset(vis,0,sizeof(vis));
        int cur = 0;
        int mLs = 10000;
        int mRs = -1;
        for(int j = i; j >= 0; j--){
            if(!vis[a[j]]){
                vis[a[j]]=true;
                cur^=a[j];
            }
            mRs = max(rs[a[j]],mRs);
            mLs = min(ls[a[j]],mLs);
            if(mRs <= i && mLs >= j)
                dp[i] = max(dp[i],((j > 0) ? dp[j-1] : 0) + cur);
        }
        if(i > 0)
            dp[i]=max(dp[i],dp[i-1]);
    }
    printf("%d\n",dp[N-1]);
    return 0;
}
