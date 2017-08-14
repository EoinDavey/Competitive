#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> ii;

const long long MX_N=505,MX_M=10001,INF=1000000000;
long long N,M,S,T,f;
long long res[MX_N][MX_N];
long long graph[MX_N][MX_N];
long long dist[MX_N];
long long p[MX_N];

void aug(int u, long long minE){
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
    scanf("%lld %lld %lld %lld",&N,&M,&S,&T);
    long long u,v,c;
    for(int i = 0; i < M; i++){
        scanf("%lld %lld %lld",&u,&v,&c);
        graph[u][v] = res[u][v] =c;
    }
    long long mf=0;
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
    printf("%lld %lld %d\n",N,mf,used.size());
    for(int i = 0; i < used.size(); i++){
        int x = used[i].first; int y = used[i].second;
        printf("%d %d %lld\n",x,y,graph[x][y]-res[x][y]);
    }
    return 0;
}
