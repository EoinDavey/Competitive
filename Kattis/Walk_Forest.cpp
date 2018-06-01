#include<bits/stdc++.h>
using namespace std;
const int MX_N = 1111, INF = 1000*1000*1000;
int memo[MX_N],dist[MX_N],N,M;

struct edge{
    int u,d;
    bool operator<(const edge &e) const {
        return d > e.d;
    }
};

vector<edge> adjList[MX_N];

int ways(int u){
    if(u==2)
        return 1;
    if(memo[u] != -1)
        return memo[u];
    int o = 0;
    for(auto &v : adjList[u])
        if(dist[v.u] < dist[u])
            o+=ways(v.u);
    return memo[u] = o;
}

int main(){
    while(scanf("%d %d",&N,&M)==2){
        int a,b,d;
        for(int i = 1; i <=N; ++i)
            dist[i] = INF,adjList[i].clear();
        memset(memo,-1,sizeof(memo));
        for(int i = 0; i < M; ++i){
            scanf("%d %d %d",&a,&b,&d);
            adjList[a].push_back({b,d});
            adjList[b].push_back({a,d});
        }
        priority_queue<edge> q;
        q.push({2,0});
        dist[2] = 0;
        while(!q.empty()){
            edge e = q.top(); q.pop();
            if(dist[e.u] < e.d)
                continue;
            for(auto &v : adjList[e.u]){
                if(e.d + v.d < dist[v.u]){
                    dist[v.u] = e.d+v.d;
                    q.push({v.u,e.d+v.d});
                }
            }
        }
        printf("%d\n",ways(1));
    }
    return 0;
}
