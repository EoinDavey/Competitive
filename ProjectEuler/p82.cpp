#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

const int N = 80;
const int INF = 1000000;
int board[N][N];
int dist[N][N];

struct path{
    int x,y,d;
    path(int _x, int _y, int _d) : x(_x),y(_y),d(_d){}
    bool operator < (path p) const {
        if(d!=p.d)
            return d > p.d;
        if(x!=p.x)
            return x < p.x;
        return y < p.y;
    }
};

int moves[][2] = {{0,1},{-1,0},{1,0}};

int main(){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d,",&board[i][j]),dist[i][j]=INF;
    priority_queue<path>  q;
    for(int i = 0; i < N; i++){
        dist[i][0] = board[i][0];
        q.push(path(i,0,board[i][0]));
    }
    int x,y,d,nx,ny,nd;
    while(!q.empty()){
        path p = q.top(); q.pop();
        x=p.x;y=p.y;d=p.d;
        if(dist[x][y] < d)
            continue;
        dist[x][y]=d;
        for(int i = 0; i < 3; i++){
            nx=x+moves[i][0]; ny=y+moves[i][1];
            if(nx < 0 || nx >=N || ny < 0 || ny >= N)
                continue;
            nd = d+board[nx][ny];
            if(nd < dist[nx][ny])
                q.push(path(nx,ny,nd));
        }
    }
    int mn = INF;
    for(int i = 0; i < N; i++)
        mn = min(mn,dist[i][N-1]);
    printf("%d\n",mn);
    return 0;
}
