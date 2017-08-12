#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

struct path {
    int x,y,d,px,py;
    path(int _x, int _y, int _d, int _px, int _py) : x(_x),y(_y),d(_d),px(_px),py(_py) {}
    bool operator < (path p) const {
        return d > p.d;
    }
};

const int MX_H = 22;
const int MX_W = 66;
const int INF = 1000000000;
int H,W;
int board[MX_H][MX_W];
int dist[MX_H][MX_W];
ii parent[MX_H][MX_W];

int moves[][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};

bool valid(int x, int y){
    return x >= 0 && x < H && y >= 0 && y < W;
}

int main(){
    while(scanf("%d %d",&H,&W),H||W){
        char _c;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                scanf(" %c",&_c);
                board[i][j] = _c-'0';
                dist[i][j]=INF;
            }
        }
        priority_queue<path> q;
        for(int i = 0; i < W; i++){
            q.push(path(0,i,board[0][i],0,i));
        }
        int x,y,d,nx,ny,nd,px,py;
        while(!q.empty()){
            path p = q.top(); q.pop();
            x = p.x; y = p.y; d = p.d; px=p.px; py=p.py;
            if(dist[x][y] <= d)
                continue;
            dist[x][y] = d;
            parent[x][y].first=px;
            parent[x][y].second=py;
            for(int i = 0; i < 8; i++){
                nx=x+moves[i][0];
                ny=y+moves[i][1];
                if(valid(nx,ny)){
                    nd=d+board[nx][ny];
                    if(dist[nx][ny]>d)
                        q.push(path(nx,ny,nd,x,y));
                }
            }
        }
        int mn = 0;
        for(int i = 0; i < W; i++){
            if(dist[H-1][i] < dist[H-1][mn])
                mn=i;
        }
        x = H-1;
        y = mn;
        while(1){
            px = parent[x][y].first;
            py = parent[x][y].second;
            board[x][y]=-1;
            if(px==x && py==y)
                break;
            x=px;y=py;
        }
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                if(board[i][j]==-1)
                    putchar(' ');
                else
                    printf("%d",board[i][j]);
            }
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}
