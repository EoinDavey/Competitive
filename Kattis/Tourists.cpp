#include<bits/stdc++.h>
using namespace std;
const int MX_SZ = 400002;
const int MX_LG = 19;
const int MX_N = 200002;
const int INF = 1000*1000*1000;
int mtable[MX_SZ][MX_LG];
int H[MX_N],E[MX_SZ],L[MX_SZ],vind;
int N;
vector<int> adjList[MX_N];

inline int rmq(int u, int v){
    if(u > v)
        return INF;
    int k = (int) floor(log2((double) (v-u+1)));
    if(L[mtable[u][k]] < L[mtable[v-(1<<k) + 1][k]])
        return mtable[u][k];
    return mtable[v-(1<<k) + 1][k];
}

void construct(int u){
    for(int i = 0; i < u; i++)
        mtable[i][0] = i;
    for(int j = 1; (1 << j) <= u; j++)
        for(int i = 0; i + (1<<j)-1 < u; ++i)
            if(L[mtable[i][j-1]] < L[mtable[i + (1 << (j-1))][j-1]])
                mtable[i][j] = mtable[i][j-1];
            else
                mtable[i][j] = mtable[i+(1<<(j-1))][j-1];
}

void vis(int u, int d){
    H[u]=vind;
    E[vind] = u;
    L[vind++] = d;
    for(auto i : adjList[u]){
        if(H[i]!=-1)
            continue;
        vis(i,d+1);
        E[vind] = u;
        L[vind++] = d;
    }
}

int LCA(int u, int v){
    int ind = rmq(min(H[u],H[v]),max(H[u],H[v]));
    return E[ind];
}

int dist(int u, int v){
    int a = H[u];
    int b = H[v];
    int ind = LCA(u,v);
    return 1+abs(L[H[ind]] - L[a]) + abs(L[H[ind]] - L[b]);
}

int main(){
    memset(H,-1,sizeof(H));
    scanf("%d",&N);
    int a,b;
    for(int i = 0; i < N-1;++i){
        scanf("%d %d",&a,&b);
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    vis(1,0);
    construct(vind);
    long long sm = 0LL;
    for(int i = 1; i <= N; ++i){
        for(int j = 2*i; j<=N; j+=i){
            sm+=((long long)dist(i,j));
        }
    }
    printf("%lld\n",sm);
    return 0;
}
