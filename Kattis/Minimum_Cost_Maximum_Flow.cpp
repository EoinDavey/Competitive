#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX_N=255,INF=10000000;
int cost[MX_N][MX_N],graph[MX_N][MX_N],res[MX_N][MX_N],p[MX_N],dist[MX_N],N,M,S,T,f;
vector<int> adjList[MX_N];

void augment(int u, int minE){
    if(u==S){
        f=minE;
        return;
    }
    if(p[u]!=-1){
        augment(p[u],min(minE,res[p[u]][u]));
        res[p[u]][u]-=f;
        res[u][p[u]]+=f;
    }
}

int weight(int i, int j){
    return cost[i][j]*res[i][j];
}

int main(){
    scanf("%d %d %d %d",&N,&M,&S,&T);
    int u,v,c,w;
    for(int i = 0; i < M; i++){
        scanf("%d %d %d %d",&u,&v,&c,&w);
        graph[u][v]=res[u][v]=c;
        cost[u][v]=w;
        cost[v][u]=-w;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int mf = 0;
    while(1){
        f=0;
        for(int i = 0; i < N; i++)
            dist[i]=INF;
        dist[S]=0;
        memset(p,-1,sizeof(p));
        queue<int> q;
        q.push(S);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u==T)
                break;
            for(auto i = adjList[u].begin(); i != adjList[u].end(); i++){
                if(dist[*i]==INF && res[u][*i] > 0){
                    q.push(*i);
                    p[*i]=u;
                    dist[*i]=dist[u]+1;
                }
            }
        }
        augment(T,INF);
        if(f==0)
            break;
        mf+=f;
    }
    while(1){
        memset(dist,-1,sizeof(dist));
        memset(p,-1,sizeof(p));
        dist[T]=0;
        for(int k = 0; k < N-1; k++){
            for(int i = 0; i < N; i++){
                for(auto j = adjList[i].begin(); j != adjList[i].end(); j++){
                    if(dist[*j] > dist[i] + res[i][*j]){
                        dist[*j] = min(dist[*j],dist[i]+res[i][*j]);
                        p[*j]=i;
                    }
                }
            }
        }
        bool negCycle=false;;
        for(int i = 0; i < N; i++)
            for(auto j = adjList[i].begin(); j != adjList[i].end(); j++)
                if(dist[*j] > dist[i]+cost[i][*j])
                    negCycle=true;
        vector<int> cyc;
        memset(dist,-1,sizeof(dist));
        dist[T]=0;
        int u = T;
        while(dist[u]!=0){
            dist[u]=0;
            cyc.push_back(u);
            u=p[u];
        }
        int mn=INF;
        for(auto i = cyc.begin(); i != cyc.end(); i++)
            mn=min(mn,res[p[u]][u]);
    }
    ll cst=0;
    for(int i = 0; i < N; i++){
        for(auto j = adjList[i].begin(); j != adjList[i].end(); j++){
            if(graph[i][*j] > 0 && res[i][*j] < graph[i][*j]){
                cst+=((ll)cost[i][*j])*((ll)(graph[i][*j]-res[i][*j]));
            }
        }
    }
    printf("%d %lld\n",mf,cst);
    return 0;
}
