#include<bits/stdc++.h>
using namespace std;

constexpr int MX_M = 11;
constexpr int MX_N = 10001;
constexpr int MD = 1000000007;
char inp[100];
int N,M;
int dfa[2][MX_M];
int memo[MX_M][MX_N];

int dp(int u, int n){
    if(memo[u][n] != -1)
        return memo[u][n];
    if(n==0)
        return u!=M;
    return memo[u][n] = ((dp(dfa[0][u],n-1) % MD) + (dp(dfa[1][u],n-1) %MD)) %MD;
}

int main(){
    int T; scanf("%d",&T);
    while(T-->0){
        memset(memo,-1,sizeof(memo));
        memset(dfa,0,sizeof(dfa));
        scanf("%d %s",&N,inp);
        M = strlen(inp);
        dfa[inp[0]-'0'][0] = 1;
        int X = 0;
        for(int j = 1; j < M; ++j){
            dfa[0][j] = dfa[0][X];
            dfa[1][j] = dfa[1][X];
            dfa[inp[j]-'0'][j] = j+1;
            X = dfa[inp[j]-'0'][X];
        }
        dfa[0][M] = dfa[1][M] = M;
        printf("%d\n",dp(0,N));
    }
    return 0;
}
