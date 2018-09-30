#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int MX_N = 5005;
const int INF = 1000*1000*1000;
const double EPS = 1e-6;
int board[MX_N][MX_N];
int N,M;
int moves[][2] = {0,1,1,0};
ii dp[MX_N][MX_N];

bool is_valid(int x,int y){return x >= 0 && y >= 0 && x < N && y < M;}

int main(){
    scanf("%d %d",&N,&M);
    for(int i = 0; i < N; ++i)for(int j = 0; j < M; ++j)scanf("%d",&board[i][j]);
    dp[0][0] = {board[0][0],board[0][0]};
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(i||j)
                dp[i][j] = {-INF,-INF};
            if(is_valid(i-1,j))
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if(is_valid(i,j-1))
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
            if(i||j){
                dp[i][j].second = dp[i][j].second + board[i][j];
                dp[i][j].first = min(dp[i][j].first, dp[i][j].second);
            }
        }
    }
    printf("%d\n",max(1,-dp[N-1][M-1].first + 1));
    return 0;
}
