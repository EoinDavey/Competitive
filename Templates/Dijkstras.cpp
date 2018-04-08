struct path {
    int u,d;
    path(int _u, int _d) : u(_u), d(_d) {}
    path(){}
    bool operator < (const path& p) const { 
        return d > p.d;
    }
};
for(int i =0; i < N; ++i)
    dist[i] = INF;
dist[S] = 0;
priority_queue<path> q;
q.push(path(S,0));
while(!q.empty()){
    path p = q.top(); q.pop();
    u = p.u,d = p.d;
    if(dist[u] < d)
        continue;
    for(auto v : adjList[u]){
        nd = d + v.second;
        if(nd < dist[v.first]){
            dist[v.first] = nd;
            q.push(path(v.first,nd));
        }
    }
}
