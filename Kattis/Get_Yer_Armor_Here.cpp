#include<bits/stdc++.h>
using namespace std;
const int MX_N = 5005;
const double EPS = 1e-6;
int board[MX_N][MX_N];
int N,M;
int moves[][2] = {0,1,0,-1,1,0,-1,0};

double dis(int x,int y){return abs(x-0.5*(N-1)) + abs(y-0.5*(M-1));}
bool is_valid(int x,int y){return x >= 0 && y >= 0 && x < N && y < M;}

int main(){
    scanf("%d %d",&N,&M);
    for(int i = 0; i < N; ++i)for(int j = 0; j < M; ++j)scanf("%d",&board[i][j]);
    double mdis = 1e10;
    int tx,ty;
    for(int i = 0; i < N; ++i) for(int j = 0; j < M; ++j)
            if(dis(i,j) < mdis)
                tx=i,ty=j,mdis=dis(i,j);
            else if((dis(i,j)-mdis)<=EPS && board[i][j] > board[tx][ty])
                tx = i, ty= j;
    int scrap = 0;
    for(;;){
        scrap+=board[tx][ty];
        board[tx][ty] = 0;
        int nx,ny,dx,dy;
        nx = tx;ny=ty;
        for(int k = 0; k < 4; ++k){
            dx = tx+moves[k][0];
            dy = ty+moves[k][1];
            if(is_valid(dx,dy) && board[dx][dy] > board[nx][ny])
                nx = dx,ny=dy;
        }
        if(nx==tx&&ny==ty)
            break;
        tx = nx;ty=ny;
    }
    printf("%d\n",scrap);
    return 0;
}
