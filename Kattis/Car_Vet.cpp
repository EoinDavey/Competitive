#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef pair<int, int> ii;
const int MX_NM = 260;
const int MX_CRS = 62505;
const int INF = 1000*1000;
int grd[MX_NM][MX_NM];
int N, M;
int mvs[][3] = {0,1,0,0,-1,0,1,0,1,-1,0,1};
int dist[MX_NM][MX_NM];
ii par[MX_NM][MX_NM];

inline bool valid(int i, int j){return i>=0 && j >= 0 && i < N && j < M; }

ii mvToEnd(int i, int j){
    if(grd[i][j] == -1)
        return {i,j};
    for(int k = 0; k < 4; ++k){
        int nx,ny;nx = i + mvs[k][0];ny = j + mvs[k][1];
        if(valid(nx,ny) && grd[nx][ny]==grd[i][j])
            return {nx,ny};
    }
}

int orient(int i, int j){
    for(int k = 0; k < 4; ++k){
        int nx,ny;nx = i + mvs[k][0];ny = j + mvs[k][1];
        if(valid(nx,ny) && grd[nx][ny]==grd[i][j])
            return mvs[k][2];
    }
}

int main(){
    scanf("%d %d",&N,&M);
    ii strt;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            par[i][j] = {-1,-1};
            scanf("%d",&grd[i][j]);
            if(grd[i][j]==-1)
                strt = {i,j};
        }
    }
    queue<ii> q;
    q.push(strt);
    dist[strt.first][strt.second] = 1;
    int x,y;
    while(!q.empty()){
        ii p = q.front();q.pop();
        x=p.first;y=p.second;
        vector<pair<int, ii> > crs;
        for(int k = 0; k < 4; ++k){
            int nx,ny;nx = x + mvs[k][0];ny = y + mvs[k][1];
            if(valid(nx,ny) && grd[nx][ny] >= 0 && orient(nx,ny) == mvs[k][2]){
                ii p = mvToEnd(nx,ny);
                nx = p.first;ny=p.second;
                if(dist[nx][ny]==0)
                    crs.pb({grd[nx][ny], p});
            }
        }
        sort(crs.begin(), crs.end());
        for(const auto& cr : crs){
            par[cr.second.first][cr.second.second] = {x,y};
            dist[cr.second.first][cr.second.second] = dist[x][y] + 1;
            q.push(cr.second);
        }
    }
    scanf("%d %d",&x,&y);
    --x,--y;
    if(dist[x][y] > 0){
        vector<int> ans;
        while(par[x][y].first != -1){
            ans.pb(grd[x][y]);
            const ii& p = par[x][y];
            x = p.first, y = p.second;
        }
        for(auto i = ans.rbegin(); i != ans.rend(); i++){
            printf("%d ",*i);
        }
        putchar('\n');
    } else
        puts("impossible");
    return 0;
}
