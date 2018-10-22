#include<bits/stdc++.h>
using namespace std;
const int MX_N = 101;
int N, M;
int mvs[][2] = {0,1,0,-1,1,0,-1,0,1,1,-1,1,1,-1,-1,-1};
char board[MX_N][MX_N];
bool vis[MX_N][MX_N];

inline bool valid(int a, int b) { return a >= 0 && b >= 0 && a < N && b < M && board[a][b]=='#';}

void fill(int a, int b){
    vis[a][b] = true;
    for(int k = 0; k < 8; ++k){
        int nx, ny;
        nx = a+mvs[k][0];
        ny = b+mvs[k][1];
        if(valid(nx,ny) && !vis[nx][ny])
            fill(nx,ny);
    }
}
int main(){
    scanf("%d %d",&N, &M);
    for(int i = 0; i < N; ++i)for(int j = 0; j < M; ++j)scanf(" %c", &board[i][j]);
    int cnt = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(!vis[i][j] && valid(i,j)){
                ++cnt;
                fill(i,j);
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
