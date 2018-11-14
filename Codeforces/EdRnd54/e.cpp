#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define LSOne(x) (x&(-x))
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int MX_N = 3 * 100 * 1000 + 3;
vector<int> adjList[MX_N];
vector<ii> queries[MX_N];
ll tree[MX_N];
ll ans[MX_N];
int N;

void update(int k, ll v){
    for(; k < MX_N; k+=LSOne(k))
        tree[k]+=v;
}
ll query(int k){
    ll o = 0;
    for(;k;k-=LSOne(k))
        o+=tree[k];
    return o;
}
void rngeUpdate(int l, int r, ll v){
    update(l, v);
    if(r < MX_N - 1)
        update(r+1, -v);
}

void dfs(int u, int p, int dpth){
    for(auto& i : queries[u])
        rngeUpdate(dpth, dpth + i.fi, (ll) i.se);
    ans[u] = query(dpth);
    for(int v : adjList[u]){
        if(v==p)
            continue;
        dfs(v, u, dpth+1);
    }
    for(auto& i : queries[u])
        rngeUpdate(dpth, dpth + i.fi, (ll) -i.se);
}

int main(){
    scanf("%d",&N);
    int x,y;
    for(int i = 0; i < N-1; ++i){
        scanf("%d %d",&x,&y);
        adjList[x].pb(y);
        adjList[y].pb(x);
    }
    int Q; scanf("%d",&Q);
    int v,d;
    while(Q-->0){
        scanf("%d %d %d",&v,&d,&x);
        queries[v].pb({d,x});
    }
    dfs(1, -1, 1);
    for(int i = 1; i <= N; ++i)
        printf("%lld ", ans[i]);
    putchar('\n');
    return 0;
}
