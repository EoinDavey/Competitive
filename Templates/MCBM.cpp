int S,T,N,n,m,s,v;
vector<int> adjList[MX_N];
int res[MX_N][MX_N];
bool vis[MX_N];

int ff(int u, int minE){
    if(u==T)
        return minE;
    vis[u]=true;
    for(auto i : adjList[u]){
        if(!vis[i] && res[u][i] > 0){
            if(int f = ff(i, min(minE,res[u][i]))){
                res[u][i] -= f;
                res[i][u] += f;
                return f;
            }
        }
    }
    return 0;
}

int main(){
    S=0;
    N=n+m+2;
    T = N-1;
    int mf = 0;
    while(1){
        memset(vis,0,sizeof(vis));
        int f = ff(S,INF);
        if(f==0)
            break;
        mf+=f;
    }
    printf("%d\n",mf);
}
