#include<bits/stdc++.h>
using namespace std;
const int MX_N = 111;
const int MX_M = 20002;
int memo[MX_N][MX_M];
int cal[MX_N];
int N, M;

int dp(int ind, int rate) {
    int mx = 0;
    if(ind == N)
        return 0;
    if(memo[ind][rate] != -1)
        return memo[ind][rate];
    mx = max(mx, min(cal[ind],rate) + dp(ind+1,(2*rate)/3));
    mx = max(mx, dp(ind+1,rate));
    if(ind <= N-2)
        mx = max(mx, dp(ind+2,M));
    return memo[ind][rate] = mx;
}

int main(){
    memset(memo, -1, sizeof(memo));
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i)
        scanf("%d", &cal[i]);
    printf("%d\n", dp(0,M));
    return 0;
}
