#include<bits/stdc++.h>
using namespace std;
const int MX_N = 111;
const int MX_M = 10011;
int N,M;
int p[MX_N];
int find(int i){return p[i] = (i==p[i] ? i : find(p[i]));}
int join(int u, int v){
    int pu = find(u);
    int pv = find(v);
    if(pu!=pv)
        p[pu]=pv;
}
bool same(int u, int v){return find(u)==find(v);}
struct edge {
    int u,v,c,w;
    bool operator<(const edge& b) const {
        if(w!=b.w)
            return w > b.w;
        if(c!=b.c)
            return c < b.c;
        if(u!=b.u)
            return u < b.u;
        return v < b.v;
    }
};
int main(){
    scanf("%d %d",&N,&M);
    for(int i = 0; i < N;++i)
        p[i]=i;
    priority_queue<edge> q;
    int a,b,c,d;
    for(int i = 0; i < M; ++i){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        edge e{a-1,b-1,c,d};
        q.push(e);
    }
    int sum = 0;
    int o = 0;
    while(!q.empty()){
        edge e = q.top(); q.pop();
        if(same(e.u,e.v))
            continue;
        sum+=e.c;
        o+=e.w;
        join(e.u,e.v);
    }
    printf("%d %d\n",o,sum);
    return 0;
}
