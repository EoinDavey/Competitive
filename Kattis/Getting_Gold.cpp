#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;

const int MX_WH=55;
char board[MX_WH][MX_WH];
bool draft[MX_WH][MX_WH];
bool vis[MX_WH][MX_WH];
int W,H;

int moves[][2]={{0,1},{0,-1},{1,0},{-1,0}};

bool valid(int x, int y){
    return x >= 0 && x < H && y >=0 && y < W;
}

int dfs(int x, int y){
    int sm=0;
    vis[x][y]=true;
    if(board[x][y]=='G')
        sm+=1;
    if(draft[x][y])
        return sm;
    for(int i = 0; i < 4; i++){
        int nx=x+moves[i][0];
        int ny=y+moves[i][1];
        if(valid(nx,ny) && !vis[nx][ny] && board[nx][ny]!='#')
            sm+=dfs(nx,ny);
    }
    return sm;
}

int main(){
    scanf("%d %d",&W,&H);
    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
            scanf(" %c",&board[i][j]);
    int px,py;
    for(int i = 0;i < H; i++){
        for(int j = 0; j < W; j++){
            if(board[i][j]=='T'){
                for(int k = 0; k < 4; k++){
                    int ni=i+moves[k][0];
                    int nj=j+moves[k][1];
                    if(valid(ni,nj))
                        draft[ni][nj]=true;
                }
            } else if(board[i][j]=='P'){
                px=i;py=j;
            }
        }
    }
    printf("%d\n",dfs(px,py));
    return 0;
}
