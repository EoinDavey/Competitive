#include<bits/stdc++.h>
using namespace std;
const int MX_NK = 404;;
int N,K;

double memo[MX_NK][MX_NK];
bool st[MX_NK][MX_NK];

double dp(int n, int k){
    if(k==0)
        return N-n;
    if(st[n][k])
        return memo[n][k];
    if(n==0){
        memo[n][k] = 0.5*dp(1,k-1) + 0.5*dp(0,k-1);
        st[n][k] = true;
        return memo[n][k];
    }
    st[n][k] = true;
    return memo[n][k] = 0.5*dp(n-1,k-1) + 0.5*dp(n,k-1);
}

int main(){
    scanf("%d %d",&N,&K);
    printf("%.8lf\n",dp(N,K));
    return 0;
}
