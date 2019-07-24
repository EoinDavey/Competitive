struct path {
    int u, wght;
    bool operator<(const path& rhs) const {
        return wght > rhs.wght;
    }
};
int h(int x) { // heuristic function
    // Don't overestimate, should be 0 at sink
    return 0; // 0 for djikstras
}
for(int i =0; i < N; ++i)
    dist[i] = INF;
dis[S] = 0;
priority_queue<path> pq;
pq.push({s, h(s)});
while(!pq.empty()){
    path p = pq.top(); pq.pop();

    if(p.u == t)
        return p.wght;

    int d = p.wght - h(p.u);

    if(dis[p.u] < d)
        continue;

    for(auto v : adjList[p.u]) {
        int nd = d + v.second;

        if(dis[v.first] <= nd)
            continue;

        dis[v.first] = nd;

        pq.push({v.first, nd + h(v.first)});
    }
}
