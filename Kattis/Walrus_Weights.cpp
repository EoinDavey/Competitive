#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; scanf("%d",&N);
    bool dp[N][2002];
    memset(dp,0,sizeof(dp));
    int a[N];
    for(int i = 0; i < N; i++)
        scanf("%d",&a[i]);
    dp[0][0]=true;
    dp[0][a[0]]=true;
    for(int i = 1; i < N; i++)
        for(int j = 0; j <= 2000; j++)
            dp[i][j] = dp[i-1][j] | (a[i]<=j ? dp[i-1][j-a[i]] : 0);
    int mn=50000;
    for(int i = 2000; i >=0; i--){
        if(dp[N-1][i] && abs(1000-i) < abs(1000-mn))
            mn=i;
    }
    printf("%d\n",mn);
    return 0;
}
