int dist[MX_N];
vector<int> adjList[MX_N];

int main(){
    for(int i = 0; i < MX_N; i++)
        dist[i]=INF;
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        int d = dist[u];
        for(int i : adjList[u]){
            if(dist[i]==INF){
                dist[i]=d+1;
                q.push(i);
            }
        }
    }
    return 0;
}
