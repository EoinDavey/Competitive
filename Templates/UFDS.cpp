int find(int u){ return p[u] = (p[u] == u ? u : find(p[u])); }

inline void join(int a, int b){
    pa = find(a);
    pb = find(b);
    if(pa!=pb){
        if(rank[pa] < rank[pb]){
            ni = pb;
            pb = pa;
            pa = ni;
        }
        p[pb] = pa;
        if(rank[pa]==rank[pb])
            rank[pa]++;
    }
}
