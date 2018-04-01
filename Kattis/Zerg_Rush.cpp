#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int MX_N = 155;
const int INF = 1000;
const int K = 8;
const ii INF_P = {INF,INF};
int dist[2][MX_N][MX_N];
int board[MX_N][MX_N];
int nboard[MX_N][MX_N];
int hlth[MX_N][MX_N];
int nhlth[MX_N][MX_N];
bool fought[MX_N][MX_N];
ii npos[MX_N][MX_N];
int run[2][4];
int N;
int moves[][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
int stats[2][2];

inline bool valid(int x, int y){ return x>=0 && y >= 0 && x < N && y < N;}

inline void upDist(int x, int y, int z, int p){
    run[p][z] = (board[x][y]==(p ? 1 : 2)) ? 0 : run[p][z] + 1;
    dist[p][x][y] = min(dist[p][x][y], run[p][z]);
}

void buildDist(int p){
    for(int i= 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            dist[p][i][j] = INF;
    queue<ii> q;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(board[i][j]==(p?1:2)){
                q.push({i,j});
                dist[p][i][j]=0;
            }
        }
    }
    ii pr;
    int x,y,nx,ny;
    while(!q.empty()){
        pr = q.front(); q.pop();
        x = pr.first,y=pr.second;
        for(int k = 0;  k < K; k+=2){
            nx = x+moves[k][0];
            ny = y+moves[k][1];
            if(valid(nx,ny) && dist[p][nx][ny]==INF){
                q.push({nx,ny});
                dist[p][nx][ny] = dist[p][x][y]+1;
            }
        }
    }
}

int showDist(int p){
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(dist[p][i][j]>=INF)
                printf("I ");
            else
                printf("%d ",dist[p][i][j]);
        }
        putchar('\n');
    }
}

bool attack(int x, int y, int p){
    for(int k = 0; k < K; ++k){
        int nx,ny;
        nx = x+moves[k][0];
        ny = y+moves[k][1];
        if(valid(nx,ny) && dist[p][nx][ny]==0){
            hlth[nx][ny] -= 5+stats[p][0] - stats[1-p][1];
            return true;
        }
    }
    return false;
}

void move(int x, int y, int p){
    if(fought[x][y]){
        return;
    }
    int mn = INF;
    for(int k = 0; k < 8; ++k){
        int nx,ny;
        nx = x+moves[k][0];
        ny = y+moves[k][1];
        if(valid(nx,ny))
            mn = min(dist[p][nx][ny],mn);
    }
    if(mn==INF){
        fought[x][y] = true;
        return;
    }
    for(int k = 0; k < 8; ++k){
        int nx,ny;
        nx = x+moves[k][0];
        ny = y+moves[k][1];
        if(valid(nx,ny) && dist[p][nx][ny] == mn){
            if(npos[nx][ny] == INF_P)
                npos[nx][ny] = {x,y};
            else
                fought[x][y]=true;
            break;
        }
    }
}

void halt(int x, int y){
    ii p = npos[x][y];
    npos[x][y] = {x,y};
    if(p==INF_P)
        return;
    halt(p.first,p.second);
}

void resolveMoves(){
    for(int i= 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            if(board[i][j]!=0 && fought[i][j])
                halt(i,j);
}

void makeMoves(){
    memset(nboard,0,sizeof(nboard));
    memset(nhlth,0,sizeof(nhlth));
    for(int i= 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            ii p = npos[i][j];
            if(p!=INF_P){
                nboard[i][j] = board[p.first][p.second];
                nhlth[i][j] = hlth[p.first][p.second];
            }
        }
    }
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            board[i][j] = nboard[i][j];
            hlth[i][j] = nhlth[i][j];
        }
    }
}

int main(){
    scanf("%d",&N);
    for(int i =0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
            scanf("%d",&stats[i][j]);
    char c;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            scanf(" %c",&c);
            board[i][j] = c=='.' ? 0 : c=='1' ? 1 : 2;
            hlth[i][j] = 35;
        }
    }
    int T;scanf("%d",&T);
    while(T-->0){
        buildDist(0);
        buildDist(1);
        memset(fought,0,sizeof(fought));
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(board[i][j]==1)
                    fought[i][j] = attack(i,j,0);
                else if(board[i][j]==2)
                    fought[i][j] = attack(i,j,1);
            }
        }
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(hlth[i][j] <= 0)
                    board[i][j] = 0;
                npos[i][j] = INF_P;
            }
        }
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j)
                if(board[i][j]==1)
                    move(i,j,0);
                else if(board[i][j]==2)
                    move(i,j,1);
        }
        resolveMoves();
        makeMoves();
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                hlth[i][j] = min(35,hlth[i][j]+1);
    }
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(board[i][j]==0)
                putchar('.');
            else
                printf("%d",board[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
