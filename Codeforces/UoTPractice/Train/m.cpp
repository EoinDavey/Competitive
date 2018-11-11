#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
struct edge{ int v,c1,c2; };
int N, tot;
const int MX_N = 100010;

vector<edge> adjList[MX_N];
int H[2*MX_N+1], E[2*MX_N+1], L[2*MX_N+1], down[MX_N], up[MX_N];
int mtable[2*MX_N+1][20];
int vind = 0;

/*
 * H[u] is first visit of u
 * E[x] is vertex at time x
 * L[x] is depth at time x
 */
void vis(int u, int d){
    H[u]=vind;
    E[vind] = u;
    L[vind++] = d;
    for(const auto& i : adjList[u]){
        if(H[i.v] != -1)
            continue;
        vis(i.v, d+1);
        E[vind] = u;
        L[vind++] = d;
    }
}

inline int rmq(int u, int v){
    if(u > v)
        return 200000000;
    int k=(int)floor(log2((double)(v-u+1)));
    if(L[mtable[u][k]]<
            L[mtable[v-(1<<k)+1][k]])
        return mtable[u][k];
    return mtable[v-(1<<k) + 1][k];
}

int LCA(int u, int v){
    if(H[u] > H[v]){
        int t = u;
        u = v;
        v = t;
    }
    //run some range min query on L
    //between H[u] and H[v]
    int ind = rmq(H[u],H[v]);
    return E[ind];
}

void hang(int u, int p){
    for(const auto& i : adjList[u]){
        if(i.v!=p){
            down[i.v] = down[u] + i.c1;
            up[i.v] = up[u] + i.c2;
            hang(i.v, u);
        }
    }
}

int main(){
    int T; scanf("%d",&T);
    while(T-->0) {
        memset(H, -1, sizeof(H));
        memset(L, 0, sizeof(L));
        memset(E, 0, sizeof(E));
        memset(down, 0, sizeof(down));
        memset(up, 0, sizeof(up));
        vind = 0;
        tot = 0;
        scanf("%d",&N);
        for(int i = 1; i <= N; ++i)
            adjList[i].clear();

        int u,v, c1, c2;
        for(int i = 0; i < N-1; ++i){
            scanf("%d %d %d %d", &u, &v, &c1, &c2);
            tot += c1; tot+=c2;
            adjList[u].pb({v,c1, c2});
            adjList[v].pb({u,c2, c1});
        }
        down[1] = up[1] = 0;
        hang(1, -1);
        vis(1, 0);

        for(int i = 0; i < vind; i++)
            mtable[i][0] = i;

        for(int j = 1; (1 << j) <= vind; j++)
            for(int i = 0; i + (1<<j)-1 < vind; ++i)
                if(L[mtable[i][j-1]]
                        <L[mtable[i+(1<<(j-1))][j-1]])
                    mtable[i][j]= mtable[i][j-1];
                else
                    mtable[i][j]=mtable[i+(1<<(j-1))][j-1];

        int Q; scanf("%d",&Q);
        while(Q-->0){
            scanf("%d %d",&u,&v);
            int lca = LCA(u,v);
            int pthcost = down[u] - down[lca] + up[v] - up[lca];
            printf("%d\n", tot-pthcost);
        }
    }
    return 0;
}
