typedef pair<int,int> ii;

int N,M,S,T,f;
int res[MX_N][MX_N];
int graph[MX_N][MX_N];
int dist[MX_N];
int p[MX_N];

void aug(int u, int minE){
    if(u==S){
        f=minE;
        return;
    }
    if(p[u]!=u){
        aug(p[u],min(minE,res[p[u]][u]));
        res[p[u]][u]-=f;
        res[u][p[u]]+=f;
    }
}

int main(){
    int mf=0;
    while(1){
        f=0;
        for(int i = 0; i < N; i++)
            dist[i]=INF,p[i]==i;
        dist[S]=0;
        queue<int> q;
        q.push(S);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u==T)
                break;
            for(int i = 0; i < N; i++){
                if(res[u][i] > 0 && dist[i]==INF){
                    dist[i]=dist[u]+1;
                    p[i]=u;
                    q.push(i);
                }
            }
        }
        aug(T,INF);
        if(f==0)
            break;
        mf+=f;
    }
    vector<ii> used;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(graph[i][j] > 0 && res[i][j] < graph[i][j])
                used.push_back(make_pair(i,j));
}
