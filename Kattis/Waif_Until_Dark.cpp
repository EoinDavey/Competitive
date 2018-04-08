#include<bits/stdc++.h>
using namespace std;
const int MX_N = 303;
const int S = 0;
const int T = MX_N - 1;
const int INF = 1000*1000*1000 + 1;
vector<int> adjList[MX_N];
int N,M,P;
int res[MX_N][MX_N];
bool vis[MX_N];

int ff(int u, int minE){
    if(u==T)
        return minE;
    vis[u]=true;
    for(int v : adjList[u])
        if(!vis[v] && res[u][v] > 0)
            if(int f = ff(v,min(minE,res[u][v]))){
                res[u][v]-=f;
                res[v][u]+=f;
                return f;
            }
    return 0;
}

int main(){
    scanf("%d %d %d",&N,&M,&P);
    bool lim[M+1]; memset(lim,0,sizeof(lim));
    for(int i = 1; i <= N; ++i){
        adjList[S].push_back(i);
        adjList[i].push_back(S);
        res[S][i] = 1;
        int k,a; scanf("%d",&k);
        for(int j = 0; j < k; ++j){
            scanf("%d",&a);
            adjList[i].push_back(N+a);
            adjList[N+a].push_back(i);
            res[i][N+a] = 1;
        }
    }
    for(int i = 1; i <= P; ++i){
        int l,t,r; scanf("%d",&l);
        for(int j = 0; j < l;++j){
            scanf("%d",&t);
            adjList[N+t].push_back(N+M+i);
            adjList[N+M+i].push_back(N+t);
            res[N+t][N+M+i] = 1;
            lim[t] = true;
        }
        scanf("%d",&r);
        adjList[N+M+i].push_back(T);
        adjList[T].push_back(N+M+i);
        res[N+M+i][T] = r;
    }
    for(int i = 1; i <= M; ++i){
        if(!lim[i]){
            adjList[N+i].push_back(T);
            adjList[T].push_back(N+i);
            res[N+i][T] =1;
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
    printf("%d\n",mf);
    return 0;
}
