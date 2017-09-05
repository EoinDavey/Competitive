#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

const int MX_RC=404,INF=1000000;
char board[MX_RC][MX_RC];
int R,C;
int sR,sC;
int dist[MX_RC][MX_RC];

const int moves[][2] = {{0,1},{0,-1},{1,0},{-1,0}};

bool valid(int i, int j){
    return i >= 0 && j >= 0 && i < R && j < C && board[i][j]!='#';
}

struct path{
    int d;
    ii u;
    path(ii _u, int _d) : u(_u), d(_d) {}
    bool operator < (const path &p) const {
        return d > p.d;
    }
};

int main(){
    scanf("%d %d",&R,&C);
    memset(board,'D',sizeof(board));
    R+=2; C+=2;
    for(int i = 1; i < R-1; i++)
        for(int j = 1; j < C-1; j++)
            scanf(" %c",&board[i][j]);
    scanf("%d %d",&sR,&sC);
    for(int i = 0;i  < R; i++)
        for(int j = 0; j < C; j++)
            dist[i][j]=INF;
    priority_queue<path> q;
    q.push(path(make_pair(sR,sC),0));
    while(!q.empty()){
        path p = q.top(); q.pop();
        int d = p.d;
        int x = p.u.first;
        int y = p.u.second;
        if(dist[x][y] <= d)
            continue;
        dist[x][y] = d;
        for(int k = 0; k < 4; k++){
            int nx = x+moves[k][0];
            int ny = y+moves[k][1];
            if(valid(nx,ny)){
                int nd = d+(board[nx][ny]=='c');
                if(dist[nx][ny] > nd)
                    q.push(path(make_pair(nx,ny),nd));
            }
        }
    }
    printf("%d\n",dist[0][0]+1);
    return 0;
}
