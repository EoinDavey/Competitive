#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

typedef pair<int,int> ii;

const int MX_N=111;
const int INF = 100000000;
char board[MX_N][MX_N];
int dist[3][MX_N][MX_N];
int H,W;

int moves [][2] = {{0,1},{0,-1},{1,0},{-1,0}};

bool valid(int x, int y){
    if(!(x >=0 && x < H && y >= 0 && y < W))
        return false;
    return board[x][y]!='*';
}

struct path {
    int x,y,d;
    path(int _x, int _y, int _d) : x(_x), y(_y), d(_d) {}
    bool operator < (path p) const {
        if(d!=p.d)
            return d > p.d;
        if(x!=p.x)
            return x < p.x; 
        return y < p.y;
    }
};

int dijkstras(ii source, int id) {
    for(int i =0; i < H; i++)
        for(int j = 0; j < W; j++)
            dist[id][i][j]=INF;
    priority_queue<path> q;
    q.push(path(source.first,source.second,0));
    int x,y,d,nx,ny,nd;
    while(!q.empty()){
        path p = q.top(); q.pop();
        x=p.x;y=p.y;d=p.d;
        if(dist[id][x][y]<=d)
            continue;
        dist[id][x][y] = d;
        for(int i = 0; i < 4; i++){
            nx=x+moves[i][0];ny=y+moves[i][1];
            nd = d + (board[x][y]=='#' ? 1:0);
            if(valid(nx,ny) && dist[id][nx][ny] > nd)
                q.push(path(nx,ny,nd));
        }
    }
}

int main(){
    int T; scanf("%d",&T);
    while(T --> 0){
        scanf("%d %d",&H,&W);
        ii p[2];
        int px=0;
        memset(board,'.',sizeof(board));
        for(int i = 1; i <= H; i++){
            for(int j = 1; j <= W; j++){
                scanf(" %c",&board[i][j]);
                if(board[i][j]=='$'){
                    p[px].first=i;
                    p[px++].second=j;
                }
            }
        }
        H+=2;W+=2;
        dijkstras(make_pair(0,0),0);
        dijkstras(p[0],1);
        dijkstras(p[1],2);
        int mn=INF;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                mn=min(mn,dist[0][i][j]+dist[1][i][j]+dist[2][i][j]+(board[i][j]=='#'?1:0));
            }
        }
        printf("%d\n",mn);
    }
    return 0;
}
