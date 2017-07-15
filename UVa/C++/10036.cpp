#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int a[10011];
int N,K;

int posmod(int n, int k){
    return (n % k + k) % k;
}

int main(){
    int M;
    scanf("%d",&M);
    for(int _m = 0; _m < M; _m++){
        scanf("%d %d",&N,&K);
        int _t;
        for(int i = 0; i < N; i++){
            scanf("%d",&_t);
            a[i]=posmod(_t,K);
        }
        bool dp[N+3][K+3];
        memset(dp,false,sizeof(dp));
        dp[0][a[0]]=true;
        for(int i = 1; i < N; i++)
            for(int j = 0; j < K; j++)
                dp[i][j] = dp[i-1][posmod(j-a[i],K)] || dp[i-1][posmod(j+a[i],K)];
        if(dp[N-1][0])
            printf("Divisible\n");
        else printf("Not divisible\n");
    }
    return 0;
}
