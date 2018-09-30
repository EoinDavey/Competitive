#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int MX_N = 5005;
const int MX_S = 10;
const int INF = 1000*1000*1000;
int N,M,S;
int to_ind(int v, int s){
    return v + s*N;
}
vector<ii> adjList[MX_N*MX_S];
int dist[MX_N*MX_S];

struct node{
    int u, d;
    bool operator<(const node& b) const {
        if(d != b.d)
            return d > b.d;
        return u > b.u;
    }
};

int main(){
    scanf("%d %d %d",&N,&M,&S);
    for(int i = 0; i < N; ++i)
        for(int s = 0; s <=S; ++s)
            dist[to_ind(i,s)] = INF;
    int u,v,t,iu,iv;
    for(int i = 0; i < M; ++i){
        scanf("%d %d %d",&u,&v,&t);
        --u,--v;
        for(int s = 0; s <= S; ++s){
            iu = to_ind(u,s);
            iv = to_ind(v,s);
            adjList[iu].push_back({iv,t});
            adjList[iv].push_back({iu,t});
            if(s){
                adjList[iu].push_back({to_ind(v,s-1),0});
                adjList[iv].push_back({to_ind(u,s-1),0});
            }
        }
    }
    int s,e; scanf("%d %d",&s,&e);
    --s,--e;
    priority_queue<node> q;
    q.push({to_ind(s,S),0});
    dist[to_ind(s,S)] = 0;
    while(!q.empty()){
        node u = q.top();q.pop();
        if(dist[u.u] < u.d)
            continue;
        for(auto& v : adjList[u.u]){
            int nd = u.d + v.second;
            if(dist[v.first] > nd){
                dist[v.first] = nd;
                q.push({v.first,nd});
            }
        }
    }
    int mn = INF;
    for(int s = 0; s <= S; ++s){
        mn = min(mn, dist[to_ind(e,s)]);
    }
    if(mn<INF)
        printf("%d\n",mn);
    else
        puts("retreat");
    return 0;
}
