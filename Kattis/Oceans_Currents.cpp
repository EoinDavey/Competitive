#include<bits/stdc++.h>
using namespace std;

struct path {
    int ux,uy,d;
    path(int _ux, int _uy, int _d) : ux(_ux), uy(_uy), d(_d) {}
    path(){}
    bool operator < (const path &p) const {
        return d > p.d;
    }
};

constexpr int moves[][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

constexpr int MX_RC=1001, INF=10000000;
int board[MX_RC][MX_RC];
int dist[MX_RC][MX_RC];
int R,C;

inline bool valid(int i, int j){
    return i>=0 && j >= 0 && i < R && j < C;
}

int main(){
    scanf("%d %d",&R,&C);
    char c;
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            scanf(" %c",&c);
            board[i][j] = c-'0';
        }
    }
    int n; scanf("%d",&n);
    int rs,cs,rd,cd;
    int ux,uy,d,nx,ny,nd;
    while(n-->0){
        scanf("%d %d %d %d",&rs,&cs,&rd,&cd);
        --rs,--cs,--rd,--cd;
        for(int i = 0; i < R; ++i)
            for(int j = 0; j < C; ++j)
                dist[i][j] = INF;
        if(rs==rd && cs==cd){
            puts("0");
            continue;
        }
        dist[rs][cs] = 0;
        priority_queue<path> q;
        q.push(path(rs,cs,0));
        while(!q.empty()){
            path p = q.top(); q.pop();
            ux = p.ux, uy=p.uy,d=p.d;
            if(dist[ux][uy] < d)
                continue;
            for(int i = 0; i < 8; ++i){
                nx = ux+moves[i][0];
                ny = uy+moves[i][1];
                nd = d+(board[ux][uy]!=i);
                if(valid(nx,ny) && dist[nx][ny] > nd){
                    dist[nx][ny] = nd;
                    q.push(path(nx,ny,nd));
                }
            }
        }
        printf("%d\n",dist[rd][cd]);
    }
    return 0;
}
