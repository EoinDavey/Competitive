#include<bits/stdc++.h>
using namespace std;

constexpr int MX_SZ = 500,INF=10000000;
constexpr double EPS = 1e-6;
int N,M,S,T;
double x[MX_SZ], y[MX_SZ];
map<int,int> res5[MX_SZ];
map<int,int> res10[MX_SZ];
map<int,int> res20[MX_SZ];
bool vis[MX_SZ];
int p[MX_SZ];

inline double dist(int i, int j){
    return hypot(x[i]-x[j],y[i]-y[j]);
}

int ff(int u, int minE, map<int,int> res[]){
    if(u==T)
        return minE;
    vis[u]=true;
    for(auto i = res[u].begin(); i != res[u].end(); i++){
        if(!vis[i->first] && i->second > 0){
            if(int f = ff(i->first, min(minE,i->second), res)){
                i->second -= f;
                res[i->first][u] += f;
                return f;
            }
        }
    }
    return 0;
}

int mf(map<int,int> res[]){
    int mf = 0;
    while(1){
        memset(vis,0,sizeof(vis));
        memset(p,-1,sizeof(p));
        int f = ff(S,INF, res);
        if(f==0)
            break;
        mf+=f;
    }
    return mf;
}

int main(){
    int _t=0;
    while(1){
        scanf("%d",&N);
        if(N==0)
            break;
        for(int i = 1; i <= N; ++i)
            scanf("%lf %lf",&x[i],&y[i]);
        scanf("%d",&M);
        for(int i = 1; i <= M; ++i)
            scanf("%lf %lf",&x[N+i],&y[N+i]);
        T = N+M+2;
        for(int i = 0; i < MX_SZ;++i)
            res5[i].clear(), res10[i].clear(), res20[i].clear();
        for(int i = 1; i <=N; ++i)
            for(int j = 1+N; j <=N+M; ++j)
                if(dist(i,j)+EPS <= 50.0)
                    res5[i][j] = res10[i][j] = res20[i][j] = INF;
                else if(dist(i,j) + EPS <= 100.0)
                    res10[i][j] = res20[i][j] = INF;
                else if(dist(i,j) + EPS <= 200.0)
                    res20[i][j] = INF;
        for(int i = 1; i <= N; ++i)
            res5[S][i] = res10[S][i] = res20[S][i] = 1;
        for(int i = N+1; i <= N+M; ++i)
            res5[i][T] = res10[i][T] = res20[i][T] = 1;
        printf("Scenario %d\n",++_t);
        printf("In 5 seconds %d robot(s) can escape\n",mf(res5));
        printf("In 10 seconds %d robot(s) can escape\n",mf(res10));
        printf("In 20 seconds %d robot(s) can escape\n",mf(res20));
        putchar('\n');
    }
    return 0;
}
