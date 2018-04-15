#include<bits/stdc++.h>
using namespace std;
const int MX_RC = 1001;
const int INF = 1000*1000*100;
int R,C;
int dpth[MX_RC][MX_RC];
int dist[MX_RC][MX_RC];
const int moves[][2] = {0,1,0,-1,1,0,-1,0};

struct edge {
    int x,y,w;
    bool operator<(const edge &e) const {
        return w > e.w;
    }
};

bool valid(int x, int y){ return x >= 0 && y >= 0 && x < R && y < C;}

int main(){
    scanf("%d %d",&R,&C);
    for(int i = 0; i < R; ++i)
        for(int j = 0; j< C; ++j)
            scanf("%d",&dpth[i][j]);
    for(int i = 0; i < R; ++i)
        for(int j = 0; j < C; ++j)
            dist[i][j] = INF;
    priority_queue<edge> q;
    for(int i = 0; i < R; ++i){
        dist[i][0] = dpth[i][0];
        q.push({i,0,dpth[i][0]});
    }
    int x,y,w,nx,ny,nw;
    while(!q.empty()){
        edge e = q.top(); q.pop();
        x = e.x;y=e.y;w=e.w;
        if(dist[x][y] < w)
            continue;
        for(int k = 0; k < 4; ++k){
            nx = x+moves[k][0];
            ny = y+moves[k][1];
            if(valid(nx,ny)){
                nw = max(w,dpth[nx][ny]);
                if(dist[nx][ny] > nw){
                    dist[nx][ny] = nw;
                    q.push({nx,ny,nw});
                }
            }
        }
    }
    int mn = INF;
    for(int i = 0; i < R; ++i)
        mn = min(mn,dist[i][C-1]);
    printf("%d\n",mn);
    return 0;
}
