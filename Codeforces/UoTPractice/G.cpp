#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef pair<int, int> ii;
const int MX_N = 200020;
const int INF = 1000*1000*1000;

vector<ii> adjList[MX_N/2];
vector<int> centAdj[MX_N/2];
set<int> rch[MX_N/2], rchd[MX_N/2];
int N;
int sz[MX_N/2];
bool mkd[MX_N/2];
int vind, H[MX_N/2], E[2*MX_N], L[2*MX_N];

int tree[MX_N*2+MX_N];

void construct(int p, int lind, int rind){
    if(lind==rind){
        tree[p] = lind;
        return;
    }
    if(rind<lind)
        return;
    int md = (lind+rind)/2;
    construct(2*p,lind,md);
    construct(2*p+1,md+1,rind);
    tree[p] = L[tree[2*p]] < L[tree[2*p+1]] ? tree[2*p] : tree[2*p+1];
}

int rmq(int p, int lind, int rind, int l, int r){
    if(r < lind || l > rind)
        return INF;
    if(l>=lind && r<=rind)
        return tree[p];
    int md = (l+r)/2;
    int lr = rmq(2*p, lind, rind, l, md);
    int rr = rmq(2*p+1, lind, rind, md+1, r);
    if(lr==INF)
        return rr;
    if(rr==INF)
        return lr;
    return L[lr] < L[rr] ? lr : rr;
}

void vis(int u, int d, int p){
    H[u]=vind;
    E[vind] = u;
    L[vind++] = d;
    for(auto i : centAdj[u]){
        if(i == p)
            continue;
        vis(i, d+1, u);
        E[vind] = u;
        L[vind++] = d;
    }
}

inline int lca(int u, int v){
    if(H[u] > H[v])
        swap(u,v);
    int ind = rmq(1, H[u], H[v], 0, vind-1);
    return E[ind];
}

void fill_sz(int u, int p){
    sz[u] = 1;
    for(ii& v : adjList[u]){
        if(v.first==p || mkd[v.first])
            continue;
        fill_sz(v.first,u);
        sz[u]+=sz[v.first];
    }
}

int get_centroid(int u, int n, int p){
    for(ii& v : adjList[u]){
        if(v.first==p || mkd[v.first])
            continue;
        if(sz[v.first] > n/2)
            return get_centroid(v.first, n, u);
    }
    return u;
}

int decomp(int u){
    fill_sz(u, -1);
    int cent = get_centroid(u, sz[u], -1);
    mkd[cent] = true;
    for(ii& v : adjList[cent]){
        if(mkd[v.first])
            continue;
        int r = decomp(v.first);
        centAdj[cent].pb(r);
    }
    return cent;
}

void buildRch(int u, int x, int p, set<int> t[], int tgt){
    t[x].insert(u);
    for(ii& v: adjList[u]){
        if(v.first==p || mkd[v.first] || v.second != tgt)
            continue;
        buildRch(v.first, x, u, t, tgt);
    }
}

void travCent(int u, int d){
    buildRch(u, u, -1, rch, 1);
    buildRch(u, u, -1, rchd, -1);
    mkd[u] = true;
    for(int v : centAdj[u])
        travCent(v, d+1);
}

int main(){
    scanf("%d", &N);
    int u, v;
    for(int i = 0; i < N-1; ++i){
        scanf("%d %d", &u, &v);
        --u, --v;
        adjList[u].pb({v,1});
        adjList[v].pb({u, -1});
    }
    int rt = decomp(0);
    memset(mkd, 0, sizeof(mkd));
    travCent(rt,0);

    vis(rt, 0, -1);
    construct(1, 0, vind-1);

    int M; scanf("%d", &M);
    while(M-->0){
        scanf("%d %d", &u, &v);
        --u,--v;
        int c = lca(u,v);
        if(rchd[c].count(u) > 0 && rch[c].count(v) > 0)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
