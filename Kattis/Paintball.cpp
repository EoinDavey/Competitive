#include<bits/stdc++.h>
using namespace std;

const int MX_N = 3000;
const int MX_M = 5005;
const int INF = 1000000000;
int N,M,S,T;
int res[MX_N][MX_N];
int graph[MX_N][MX_N];
int p[MX_N];
bool vis[MX_N];

int ff(int u, int minE){
    vis[u]=true;
    if(u==T)
        return minE;
    for(int i = 0; i < N; i++){
        int cap = res[u][i];
        if(!vis[i] && cap > 0){
            if(int sent = ff(i,min(minE,cap))) {
                res[i][u]+=sent;
                res[u][i]-=sent;
                return sent;
            }
        }
    }

    return 0;
}

int main(){
    scanf("%d %d",&N,&M);
    int mn=N;
    N*=2;
    N+=2;
    S=0; T=N-1;
    for(int i = 1; i <= mn; i++){
        graph[0][i]=res[0][i]=1;
    }
    int x,y;
    for(int i = mn+1; i < N-1; i++){
        graph[i][N-1]=res[i][N-1]=1;
    }
    for(int i = 0; i < M; i++){
        scanf("%d %d",&x,&y);
        graph[x][mn+y]=res[x][mn+y]=INF;
        graph[y][mn+x]=res[y][mn+x]=INF;
    }
    int mf=0;
    while(1){
        memset(vis,0,sizeof(vis));
        int f = ff(S,INF);
        if(f==0)
            break;
        mf+=f;
    }
    if(mf!=mn)
        puts("Impossible");
    else {
        for(int i = 1; i <=mn; i++){
            for(int j = mn+1; j < N-1; j++){
                if(graph[i][j] > 0 && res[i][j] < graph[i][j]){
                    printf("%d\n",j-mn);
                    break;
                }
            }
        }
    }
    return 0;
}
