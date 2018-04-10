#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
struct edge{
    int u,w;
};
struct trip{
    int a,b,c;
    bool operator<(const trip &t) const {
        if(a!=t.a)
            return a < t.a;
        if(b!=t.b)
            return b < t.b;
        return c < t.c;
    }
};
const int MX_N = 10011;
vector<edge> adjList[MX_N];
vector<edge> nAdjList[MX_N];
int N,M;
bool vis[MX_N];
set<trip> out;

edge nxt(int u, int p){
    if(adjList[u].size() != 2)
        return {u,0};
    for(const auto &v : adjList[u]){
        if(v.u!=p){
            edge e = nxt(v.u,u);
            e.w += v.w;
            return e;
        }
    }
}

inline void ins(int a, int b, int c){
    out.insert({min(a,b),max(a,b),c});
}

void trav(int u){
    vis[u] = true;
    for(const edge &v : adjList[u]){
        edge e = nxt(v.u,u);
        e.w+=v.w;
        ins(u,e.u,e.w);
        if(!vis[e.u])
            trav(e.u);
    }
}

int main(){
    int T; scanf("%d",&T);
    while(T-->0){
        scanf("%d %d",&N,&M);
        memset(vis,0,sizeof(vis));
        int a,b,c;
        for(int i = 1; i <= N; ++i)
            adjList[i].clear();
        out.clear();
        for(int i = 0; i < M; ++i){
            scanf("%d %d %d",&a,&b,&c);
            adjList[a].push_back({b,c});
            adjList[b].push_back({a,c});
        }
        for(int i = 1; i <= N; ++i)
            if(!vis[i] && adjList[i].size() != 2)
                trav(i);
        printf("%d\n",out.size());
        for(const auto &p : out)
            printf("%d %d %d\n",p.a,p.b,p.c);
        putchar('\n');
    }
    return 0;
}
