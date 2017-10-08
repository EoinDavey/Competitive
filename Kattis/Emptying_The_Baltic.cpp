#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr int MX_HW = 505, INF=100000000;
int H,W;
int dx,dy;
int board[MX_HW][MX_HW];
int dist[MX_HW][MX_HW];

int moves[][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

bool valid(int i, int j){
    return i>=0&&j>=0&&i<H&&j<W && board[i][j] > 0;
}

struct path{
    int x,y,d;
    path(int _x, int _y, int _d) : x(_x), y(_y), d(_d){}
    bool operator< (const path& p) const {
        return d > p.d;
    }
};

int main(){
    scanf("%d %d",&H,&W);
    for(int i = 0; i < H; ++i)
        for(int j = 0; j < W; ++j)
            scanf("%d",&board[i][j]);
    for(int i = 0; i < H; ++i)
        for(int j = 0; j < W; ++j)
            board[i][j]*=-1;
    for(int i = 0; i< H; ++i)
        for(int j = 0; j < W;++j)
            dist[i][j] = INF;
    scanf("%d %d",&dx,&dy);
    --dx,--dy;
    dist[dx][dy] = 0;
    priority_queue<path> q;
    q.push(path(dx,dy,0));
    while(!q.empty()){
        path p = q.top(); q.pop();
        if(dist[p.x][p.y] < p.d)
            continue;
        for(int k = 0; k < 8; ++k){
            int nx = p.x + moves[k][0];
            int ny = p.y + moves[k][1];
            if(valid(nx,ny)){
                int nd = p.d + max(0, board[dx][dy] - p.d - board[nx][ny]);
                if(dist[nx][ny] > nd){
                    dist[nx][ny] = nd;
                    q.push(path(nx,ny,nd));
                }
            }
        }
    }
    ll sm = 0;
    for(int i = 0; i < H; ++i)
        for(int j = 0; j < W; ++j)
            if(board[dx][dy] > dist[i][j])
                sm += (ll) board[dx][dy] - dist[i][j];
    printf("%lld\n",sm);
    return 0;
}
