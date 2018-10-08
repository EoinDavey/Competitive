#include<bits/stdc++.h>
#define RC(x) x+1
#define CC(x) x+33
using namespace std;
const int MX_N = 66;
const int S = 0;
const int T = MX_N-1;
const int INF = 1000*1000*1000;
vector<int> adjList[MX_N];
bool vis[MX_N];
int res[MX_N][MX_N];
int board[MX_N][MX_N];
int N;

int ff(int u, int minE){
    if(u==T)
        return minE;
    vis[u]=true;
    for(auto i : adjList[u]){
        if(!vis[i] && res[u][i] > 0){
            if(int f = ff(i, min(minE,res[u][i]))){
                res[u][i] -= f;
                res[i][u] += f;
                return f;
            }
        }
    }
    return 0;
}

bool pos(int x){
    memset(res,0,sizeof(res));
    for(int r = 0; r < N; ++r){
        adjList[RC(r)].clear();
        adjList[CC(r)].clear();
    }
    for(int r = 0; r < N; ++r){
        adjList[RC(r)].push_back(S);
        adjList[S].push_back(RC(r));
        res[S][RC(r)] = 1;
        adjList[CC(r)].push_back(T);
        adjList[T].push_back(CC(r));
        res[CC(r)][T] = 1;
        for(int c = 0; c < N; ++c){
            if(board[r][c] >= x){
                adjList[RC(r)].push_back(CC(c));
                adjList[CC(c)].push_back(RC(r));
                res[RC(r)][CC(c)] = 1;
            }
        }
    }
    int mf = 0;
    while(1){
        memset(vis,0,sizeof(vis));
        int f = ff(S,INF);
        if(f==0)
            break;
        mf+=f;
    }
    return mf==N;
}

int main(){
    scanf("%d",&N);
    for(int i = 0; i < N; ++i)for(int j = 0; j < N; ++j)scanf("%d", &board[i][j]);
    int L = 1; int R = 1000*1000;
    while(L!=R){
        int md = (L+R+1)/2;
        if(pos(md)){
            L = md;
        } else {
            R = md-1;
        }
    }
    printf("%d\n",L);
    return 0;
}
