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
