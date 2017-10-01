#include<bits/stdc++.h>
using namespace std;

constexpr int MX_M = 11, MX_N = 10001, MD = 1000000007;
char inp[100];
int N,M, dfa[MX_M][2], memo[MX_M][MX_N];

int dp(int u, int n){
    if(memo[u][n] != -1)
        return memo[u][n];
    if(n==0)
        return u!=M;
    return memo[u][n] = (dp(dfa[u][0],n-1) + dp(dfa[u][1],n-1)) %MD;
}

int main(){
    int T; scanf("%d",&T);
    while(T-->0){
        memset(memo,-1,sizeof(memo));
        memset(dfa,0,sizeof(dfa));
        scanf("%d %s",&N,inp);
        M = strlen(inp);
        dfa[0][inp[0]-'0'] = 1;
        int X = 0;
        for(int j = 1; j < M; ++j){
            dfa[j][0] = dfa[X][0];
            dfa[j][1] = dfa[X][1];
            dfa[j][inp[j]-'0'] = j+1;
            X = dfa[X][inp[j]-'0'];
        }
        dfa[M][0] = dfa[M][1] = M;
        printf("%d\n",dp(0,N));
    }
    return 0;
}
