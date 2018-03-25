#include<bits/stdc++.h>
using namespace std;
const int MX_SZ = 255;
int board[MX_SZ][MX_SZ];
bool vis[MX_SZ][MX_SZ];
int N;
int moves[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int smoves[][2] = {{0,1},{1,0}};
inline bool valid(int x, int y){ return x >= 0 && y >= 0 && x < N && y < N; }

FILE *fin,*fout;

int sz(const set<int> &s, int x, int y){
    vis[x][y] = true;
    int o = 1;
    for(int k = 0; k < 4; ++k){
        int nx = x+moves[k][0];
        int ny = y+moves[k][1];
        if(valid(nx,ny) && !vis[nx][ny] && s.count(board[nx][ny]) > 0)
            o+=sz(s,nx,ny);
    }
    return o;
}

int main(){
    fin = fopen("multimoo.in","r");
    fout = fopen("multimoo.out","w+");
    fscanf(fin,"%d",&N);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            fscanf(fin,"%d",&board[i][j]);
    int mxs = 0;
    memset(vis,0,sizeof(vis));
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            if(!vis[i][j])
                mxs = max(mxs,sz({board[i][j]},i,j));
    fprintf(fout,"%d\n",mxs);
    int mxd = 0;
    set<pair<int,int> > teams;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            for(int k = 0; k < 2; ++k){
                int ni = i + smoves[k][0];
                int nj = j + smoves[k][1];
                if(valid(ni,nj) && board[ni][nj] != board[i][j]){
                    if(teams.count({board[i][j],board[ni][nj]}) <= 0){
                        memset(vis,0,sizeof(vis));
                        mxd = max(mxd,sz({board[i][j],board[ni][nj]},i,j));
                    }
                    teams.insert({board[i][j],board[ni][nj]});
                }
            }
        }
    }
    fprintf(fout,"%d\n",mxd);
    fclose(fin);
    fclose(fout);
    return 0;
}
