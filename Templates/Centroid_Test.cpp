#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int MX_N = 200020;
const int INF = 1000*1000*1000;

vector<int> adjList[MX_N];
int N, M;
int sz[MX_N], min_rd[MX_N], centP[MX_N];
bool mkd[MX_N];
int vind, H[MX_N], E[MX_N], L[MX_N], mtable[MX_N][20];

inline int rmq(int u, int v){
    if(u > v)
        return INF;
    int k=(int)floor(log2((double)(v-u+1)));
    if(L[mtable[u][k]]<
            L[mtable[v-(1<<k)+1][k]])
        return mtable[u][k];
    return mtable[v-(1<<k) + 1][k];
}

void vis(int u, int d, int p){
    H[u]=vind;
    E[vind] = u;
    L[vind++] = d;
    for(auto i : adjList[u]){
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
    int ind = rmq(H[u],H[v]);
    return E[ind];
}

inline int dist(int u, int v){
    int a = H[u];
    int b = H[v];
    int ind = lca(u,v);
    return abs(L[H[ind]]-L[a])
        + abs(L[H[ind]]-L[b]);
}

void fill_sz(int u, int p){
    sz[u] = 1;
    for(int v : adjList[u]){
        if(v==p || mkd[v])
            continue;
        fill_sz(v,u);
        sz[u]+=sz[v];
    }
}

int get_centroid(int u, int n, int p){
    for(int v : adjList[u]){
        if(v==p || mkd[v])
            continue;
        if(sz[v] > n/2)
            return get_centroid(v, n, u);
    }
    return u;
}

int decomp(int u){
    fill_sz(u, -1);
    int cent = get_centroid(u, sz[u], -1);
    mkd[cent] = true;
    for(int v : adjList[cent]){
        if(mkd[v])
            continue;
        int r = decomp(v);
        centP[r] = cent;
    }
    return cent;
}

void update(int u, int x){
    min_rd[u] = min(min_rd[u], dist(u, x));
    if(centP[u]!=-1)
        update(centP[u], x);
}

int query(int u, int x){
    int mn = dist(u, x) + min_rd[u];
    if(centP[u]!=-1)
        mn = min(mn, query(centP[u], x));
    return mn;
}

int main(){
    memset(centP, -1, sizeof(centP));
    scanf("%d %d", &N, &M);
    int u, v;
    for(int i = 0; i < N-1; ++i){
        scanf("%d %d", &u, &v);
        --u, --v;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    decomp(0);
    vis(0, 0, -1);
    for(int i = 0; i < vind; i++)
        mtable[i][0] = i;
    for(int j = 1; (1 << j) <= vind; j++)
        for(int i = 0; i + (1<<j)-1 < vind; ++i)
            if(L[mtable[i][j-1]]
                    < L[mtable[i+(1<<(j-1))][j-1]])
                mtable[i][j]= mtable[i][j-1];
            else
                mtable[i][j]=mtable[i+(1<<(j-1))][j-1];
    for(int i = 0; i < N; ++i)
        min_rd[i] = INF;
    update(0, 0);
    while(M-->0){
        scanf("%d %d", &u, &v);
        --v;
        if(u==1)
            update(v, v);
        else
            printf("%d\n",query(v, v));
    }
    return 0;
}
