int sptable[MX_LG][MX_SZ];
int V,P; 

int H[MX_VP],E[MX_SZ],L[MX_SZ],vind;

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
    if(H[u] > H[v]){
        int t = H[u];
        H[u] = H[v];
        H[v] = t;
    }
    // Segment Tree or sparse table for RMQ
    int ind = rmq(L,H[u],H[v]);
    return E[ind];
}

int dist(int u, int v){
    int a = H[u];
    int b = H[v];
    int ind = LCA(u,v);
    return abs(L[H[ind]] - L[a]) + abs(L[H[ind]] - L[b]);
}

int main(){
    memset(H,-1,sizeof(H));
    vis(0,0);
    construct(vind,L);
    return 0;
}
