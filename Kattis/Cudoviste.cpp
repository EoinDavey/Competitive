#include<bits/stdc++.h>
using namespace std;

constexpr int MX_RC = 55, INF=100000;
int R,C;
int board[MX_RC][MX_RC];
int cnt[5];

int main(){
    scanf("%d %d",&R,&C);
    char c;
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            scanf(" %c",&c);
            if(c=='#')
                board[i][j] = INF;
            if(c=='X')
                board[i][j] = 1;
        }
    }
    for(int i = 0; i < R-1; ++i){
        for(int j = 0; j < C-1; ++j){
            int sm = board[i][j] + board[i+1][j] + board[i][j+1] + board[i+1][j+1];
            if(sm < INF)
                cnt[sm]++;
        }
    }
    for(int i = 0; i < 5; i++)
        printf("%d\n",cnt[i]);
    return 0;
}
