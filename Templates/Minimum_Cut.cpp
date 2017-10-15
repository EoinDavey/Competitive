#include<bits/stdc++.h>
using namespace std;

const int MX_N = 505;
const int INF = 100000000;
int N,M,S,T;
int graph[MX_N][MX_N];
int res[MX_N][MX_N];
vector<int> adjList[MX_N];
int p[MX_N],f;
bool vis[MX_N];
vector<int> U;
void augment(int u, int minE){
    if(u==S){ f=minE;
        return;
    }
    if(p[u]!=-1){
        augment(p[u],min(minE,res[p[u]][u]));
        res[p[u]][u]-=f;
        res[u][p[u]]+=f;
    }
}

void trav(int u){
    U.push_back(u);
    vis[u]=true;
    for(auto i = adjList[u].begin(); i != adjList[u].end(); i++){
        if(!vis[*i] && res[u][*i] > 0){
            trav(*i);
        }
    }
}

int main(){
    scanf("%d %d %d %d",&N,&M,&S,&T);
    int u,v,w;
    for(int i = 0; i < M; i++){
        scanf("%d %d %d",&u,&v,&w);
        graph[u][v] = graph[v][u] = res[u][v] = w;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int mf=0;
    while(1){
        f=0;
        memset(vis,0,sizeof(vis));
        memset(p,-1,sizeof(p));
        queue<int> q;
        vis[S]=true;
        q.push(S);
        while(!q.empty()){
            int v = q.front(); q.pop();
            if(v==T)
                break;
            for(auto i = adjList[v].begin(); i != adjList[v].end(); i++){
                if(!vis[*i] && res[v][*i] > 0){
                    p[*i]=v;
                    vis[*i]=true;
                    q.push(*i);
                }
            }
        }
        augment(T,INF);
        if(f==0)
            break;
        mf+=f;
    }
    memset(vis,0,sizeof(vis));
    trav(S);
    printf("%lu\n",U.size());
    for(int i = 0; i < U.size(); i++){
        printf("%d\n",U[i]);
    }
    return 0;
}
