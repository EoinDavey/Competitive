#include<bits/stdc++.h>
using namespace std;
typedef complex<double> cc;

const int MX=101;
const int MX_N = 300, INF=10000000;
int S,T,N,n,m,s,v;
vector<int> adjList[MX_N];
int res[MX_N][MX_N];
bool vis[MX_N];

int ff(int u, int minE){
    if(u==T)
        return minE;
    vis[u]=true;
    for(auto i = adjList[u].begin(); i != adjList[u].end(); i++){
        if(!vis[*i] && res[u][*i] > 0){
            if(int f = ff(*i, min(minE,res[u][*i]))){
                res[u][*i] -= f;
                res[*i][u] += f;
                return f;
            }
        }
    }
    return 0;
}

int main(){
    while(~scanf("%d %d %d %d",&n,&m,&s,&v)){
        memset(res,0,sizeof(res));
        S=0;
        N=n+m+2;
        T = N-1;
        for(int i = 0; i < N; i++)
            adjList[i].clear();
        for(int i = 1; i <= n; i++){
            adjList[i].push_back(S);
            adjList[S].push_back(i);
            res[S][i] = 1;
        }
        for(int i = n+1; i <= n+m; i++){
            adjList[i].push_back(T);
            adjList[T].push_back(i);
            res[i][T] = 1;
        }
        cc goph[n],hole[m];
        double _x,_y;
        for(int i = 0; i < n; i++){
            scanf("%lf %lf",&_x,&_y);
            goph[i] = cc(_x,_y);
        }
        for(int i = 0; i < m; i++){
            scanf("%lf %lf",&_x,&_y);
            hole[i] = cc(_x,_y);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(abs(goph[i]-hole[j]) <= v*s){
                    adjList[i+1].push_back(n+j+1);
                    adjList[n+j+1].push_back(i+1);
                    res[i+1][n+j+1] = INF;
                }
            }
        }
        int mf = 0;
        while(1){
            memset(vis,0,sizeof(vis));
            int f = ff(S,INF);
            if(f==0)
                break;
            mf+=f;
        }
        printf("%d\n",n-mf);
    }
    return 0;
}
