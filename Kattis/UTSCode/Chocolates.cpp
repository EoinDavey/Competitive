#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef complex<double> cc;
typedef vector<int> vi;
int moves[][2] = {0,1,0,-1,1,0,-1,0,1,1,-1,1,-1,-1,1,-1};
int R,C;
const int MX_RC = 10;
int board[MX_RC][MX_RC];

ii toCoord(int x) {
    return {1+x/C,1+x%C};
}

int valid(int x,int y){return x>=0 && y >= 0 && x <= R+1 && y <= C+1;}
bool vis[MX_RC][MX_RC];

int dfs(int x,int y){
    int s = 0;
    if(vis[x][y])
        return 0;
    vis[x][y]=true;
    for(int k = 0; k < 4; ++k){
        int nx,ny;
        nx = x+moves[k][0];ny=y+moves[k][1];
        if(valid(nx,ny) && board[nx][ny])
            s+=dfs(nx,ny);
    }
    return 1+s;
}

void fill(int x, int y){
    int s = 0;
    if(vis[x][y])
        return;
    vis[x][y]=true;
    for(int k = 0; k < 8; ++k){
        int nx,ny;
        nx = x+moves[k][0];ny=y+moves[k][1];
        if(valid(nx,ny) && !board[nx][ny])
            fill(nx,ny);
    }
}

bool check(){
    memset(vis,0,sizeof(vis));
    int tot_c = 0;
    for(int i = 1; i <= R; ++i)for(int j = 1; j <=C;++j)tot_c+=board[i][j];
    bool b = false;
    for(int i = 1; i <= R && !b; ++i) for(int j = 1; j <=C && !b;++j)
            if(board[i][j]){
                int d = dfs(i,j);
                if(d!=tot_c)
                    return false;
                b=true;
            }
    memset(vis,0,sizeof(vis));
    fill(0,0);
    for(int i = 1; i <=R; ++i)for(int j = 1; j <= C; ++j)if(!board[i][j] && !vis[i][j]) return false;
    return true;
}

int main(){
    scanf("%d %d",&R,&C);
    int sum = 0;
    for(int i = 0; i < (1<<(R*C)); ++i){
        for(int j = 0; j < R*C; ++j){
            ii u = toCoord(j);
            if((i&(1<<j))!=0)
                board[u.first][u.second] = true;
            else
                board[u.first][u.second] = false;
        }
        if(check())
            sum+=1;
        /*for(int i = 0; i < R; ++i){
            for(int j = 0; j < C; ++j)
                printf("%c ",board[i][j] ? 'x':'.');
            putchar('\n');
        }*/
    }
    printf("%d\n",sum-1);
    return 0;
}
