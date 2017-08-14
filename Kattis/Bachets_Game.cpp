#include<bits/stdc++.h>
using namespace std;

const int MX_N = 1000001;
const int MX_M = 11;
int N,M;
int a[MX_M];
bool dp[MX_N];

int main(){
    while(scanf("%d %d",&N,&M)==2){
        for(int i = 0; i < M; i++)
            scanf("%d",&a[i]);
        dp[0]=0;
        for(int i = 1; i <= N; i++){
            dp[i]=0;
            for(int j = 0; j < M; j++){
                if((i-a[j]>=0) && !dp[i-a[j]]){
                    dp[i]=1;
                    break;
                }
            }
        }
        if(dp[N])
            puts("Stan wins");
        else
            puts("Ollie wins");
    }
    return 0;
}
