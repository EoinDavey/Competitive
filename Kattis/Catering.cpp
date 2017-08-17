#include<bits/stdc++.h>
using namespace std;
const int MX_N=110;
const int MX_Z = 300;
const int INF = 10000000;
int N,K,S,T,md;
int dist[MX_N][MX_N];
int res[MX_Z][MX_Z];
int cost[MX_Z][MX_Z];
bool vis[MX_Z];

vector<int> adjList[MX_Z];

int ctl(int i) {
    return i;
}

int ctr(int i) {
    return md+i;
}

int ff(int u, int minE){
    vis[u]=true;
    if(u==T)
        return minE;
    for(auto i = adjList[u].begin(); i != adjList[u].end(); i++){
        if(!vis[*i] && res[u][*i] > 0){
            if(int f = ff(*i,min(minE,res[u][*i]))){
                res[u][*i]-=f;
                res[*i][u]+=f;
                return f;
            }
        }
    }
    return 0;
}

int main(){
    scanf("%d %d",&N,&K);
    N++;
    for(int i = 1; i < N; i++)
        for(int j = 1; j < N-i+1; j++)
            scanf("%d",&dist[i][i+j]);
    md = N;
    N*=2;
    N+=2;
    S=0;
    T=N-1;
    adjList[S].push_back(1);
    adjList[1].push_back(S);
    res[0][1] = K;
    cost[0][1]=0;
    for(int i = 2; i <= md; i++){
        adjList[S].push_back(i);
        adjList[i].push_back(S);
        res[S][i]=1;
        cost[S][i] = 0;
    }
    for(int i = 1; i < md; i++){
        for(int j = 1; j < md-i+1; j++){
            adjList[i].push_back(ctr(i+j));
            adjList[ctr(i+j)].push_back(i);
            res[i][ctr(i+j)]=1;
            cost[i][ctr(i+j)]=dist[i][i+j];
            cost[ctr(i+j)][i] = -dist[i][i+j];
        }
    }
    for(int i = md+1; i < N-1; i++){
        adjList[i].push_back(T);
        adjList[T].push_back(i);
        res[i][T]=1;
        cost[i][T]=0;
    }
    while(1){
        memset(vis,0,sizeof(vis));
        int f = ff(S,INF);
        if(f==0)
            break;
    }
    return 0;
}
