#include<bits/stdc++.h>
using namespace std;

const int MX_N=101,INF=100000000;
int N,dist[MX_N];
int w[MX_N][MX_N];
int t[MX_N];
int memo[MX_N];
int T;
vector<int> adjList[MX_N];

struct path {
    int u,d;
    path(int _u, int _d) : u(_u), d(_d) {}
    bool operator < (const path &p) const {
        return d > p.d;
    }
};

int find(int u){
    if(memo[u]!=-1)
        return memo[u];
    if(u==0)
        return t[u];
    int mx = -INF;
    for(auto i = adjList[u].begin(); i != adjList[u].end(); i++)
        if(dist[*i] + w[u][*i] == dist[u])
            mx = max(mx,find(*i));
    return memo[u] = mx+t[u];
}

int main(){
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%d",&t[i]);
    }
    int m; scanf("%d",&m);
    int a,b,d;
    for(int i = 0; i < m; i++){
        scanf("%d %d %d",&a,&b,&d);
        --a;--b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
        w[a][b] = w[b][a] = d;
    }
    for(int i = 0; i < N; i++)
        dist[i]=INF;
    priority_queue<path> q;
    q.push(path(0,0));
    while(!q.empty()){
        path p = q.top(); q.pop();
        int u = p.u;
        int d = p.d;
        if(d >= dist[u])
            continue;
        dist[u]=d;
        for(auto i = adjList[u].begin(); i != adjList[u].end(); i++){
            if(d + w[u][*i] < dist[*i])
                q.push(path(*i,w[u][*i] + d));
        }
    }
    memset(memo,-1,sizeof(memo));
    T = dist[N-1];
    if(T<INF)
        printf("%d %d\n",dist[N-1],find(N-1));
    else
        puts("impossible");
    return 0;
}
