int bidirbfs(){
    queue<int> fq, rq;
    fq.push(S); dis[S] = 0;
    rq.push(T); disr[T] = 0;

    vector<int> proc;
    for(;;){
        if(fq.empty() && rq.empty())
            return -1; // disconnected
        if(!fq.empty()){
            int u = fq.front(); fq.pop();
            for(int v : adjList[u]){
                if(dis[v] <= dis[u] + 1)
                    continue;
                dis[v] = dis[u] + 1;
                fq.push(v);
            }
            vis[u] = true;
            proc.pb(u);
        }
        if(!rq.empty()){
            int u = rq.front(); rq.pop();
            for(int v : RadjList[u]){ // REVERSE adj
                if(disr[v] <= disr[u] + 1)
                    continue;
                disr[v] = disr[u] + 1;
                rq.push(v);
            }
            if(vis[u])
                break;
            proc.pb(u);
        }
    }

    int mn = INF;
    for(int u : proc)
        if(dis[u] != INF && disr[u] != INF)
            mn = min(mn, dis[u] + disr[u]);
    return mn;
}
