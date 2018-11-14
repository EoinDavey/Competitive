#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
struct path {
    int u;
    ll w;
    path(int _u, ll _w) : u(_u), w(_w) {}
    bool operator<(const path& p) const {
        if(w!=p.w)
            return w > p.w;
        return u < p.w;
    }
};

const int MX_N = 300003;
const ll INF = 1000LL*1000LL*1000LL*1000LL*1000LL*1000LL;
ll dist[MX_N];
bool used[MX_N];
int N, M, K;
vector<tuple<int,ll,int> > adjList[MX_N];

inline void relax(queue<ii>& edges, int u){
    for(int i = 0; i < adjList[u].size(); ++i){
        int nu, x;
        ll nw;
        tie(nu,nw,x) = adjList[u][i];
        if(dist[nu] == dist[u] + nw)
            edges.push({nu, x});
    }
}

int main(){
    scanf("%d %d %d",&N,&M,&K);
    int x,y;
    ll w;
    for(int i = 0; i < M; ++i){
        scanf("%d %d %lld",&x,&y,&w);
        --x,--y;
        adjList[x].pb({y, w, i+1});
        adjList[y].pb({x, w, i+1});
    }
    for(int i = 0; i < N; ++i)
        dist[i] = INF;
    dist[0] = 0;
    priority_queue<path> q;
    q.push({0,0});
    int u;
    while(!q.empty()){
        path p = q.top(); q.pop();
        u=p.u,w=p.w;
        if(dist[u] < w)
            continue;
        int nu; ll nw;
        for(int i = 0; i < adjList[u].size(); ++i){
            tie(nu,nw,x) = adjList[u][i];
            if(dist[nu] > w + nw){
                dist[nu] = w + nw;
                q.push({nu,dist[nu]});
            }
        }
    }
    queue<ii> edges;
    int cnt = 0;
    relax(edges, 0);
    used[0] = true;
    vector<int> eUsd;
    while(cnt < K && !edges.empty()){
        ii e = edges.front(); edges.pop();
        if(used[e.fi])
            continue;
        eUsd.pb(e.se);
        used[e.fi] = true;
        relax(edges, e.fi);
        ++cnt;
    }
    printf("%d\n", cnt);
    for(int v : eUsd)
        printf("%d ",v);
    putchar('\n');
    return 0;
}
