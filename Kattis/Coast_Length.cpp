#include<iostream>
#include<cstdio>

using namespace std;

const int MX_N=1011;
int N,M;
bool board[MX_N][MX_N];
bool sea[MX_N][MX_N];
bool vis[MX_N][MX_N];

int moves[][2] = {{0,1},{0,-1},{1,0},{-1,0}};

bool valid(int x, int y){
    return x>=0 && x < N && y >=0 && y < M;
}

int dfs(int x, int y){
    vis[x][y]=true;
    int sm=0;
    for(int i = 0; i < 4; i++){
        int nx = x+moves[i][0];
        int ny = y+moves[i][1];
        if(valid(nx,ny) && !vis[nx][ny]){
            if(board[nx][ny])
                sm+=1;
            else
                sm+=dfs(nx,ny);
        }
    }
    return sm;
}

int main(){
    scanf("%d %d",&N,&M);
    int sx, sy;
    char c;
    sx=sy=-1;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            scanf(" %c",&c);
            board[i][j] = c=='1';
        }
    }
    N+=2;
    M+=2;
    printf("%d\n",dfs(0,0));
    return 0;
}
