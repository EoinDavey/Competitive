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
        int t = u;
        u = v;
        v = t;
    }
    int ind = rmq(H[u],H[v]);
    return E[ind];
}

int dist(int u, int v){
    int a = H[u];
    int b = H[v];
    int ind = LCA(u,v);
    return abs(L[H[ind]] - L[a]) + abs(L[H[ind]] - L[b]);
}
