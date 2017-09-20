#include<bits/stdc++.h>
using namespace std;

constexpr int MX_NM = 101;
char board[MX_NM][MX_NM];
int cccnt;
int col[MX_NM][MX_NM];
int N,M;

int moves[][2] = {{0,1},{0,-1},{1,0},{-1,0}};

bool valid(int x,int y){
    return x>=0 && x < N && y >= 0 && y < M;
}

void fill(int x, int y){
    col[x][y] = cccnt;
    for(int k = 0; k < 4; ++k){
        int nx = x+moves[k][0];
        int ny = y+moves[k][1];
        if(valid(nx,ny) && board[nx][ny] == '-' && col[nx][ny] == 0)
            fill(nx,ny);
    }
}

int main(){
    int _t = 1;
    while(scanf("%d %d",&N,&M)==2){
        memset(col,0,sizeof(col));
        cccnt=0;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                scanf(" %c",&board[i][j]);
        for(int i = 0; i < N;++i)
            for(int j = 0; j < M; ++j)
                if(board[i][j]=='-' && col[i][j]==0)
                    ++cccnt, fill(i,j);
        printf("Case %d: %d\n",_t++,cccnt);
    }
    return 0;
}
