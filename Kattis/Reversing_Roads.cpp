#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<cstring>

using namespace std;

typedef pair<int,int> ii;

const int MX_N=51;
int N,M;
bool adjMat[MX_N][MX_N];

bool vis[MX_N];
int dfs_num[MX_N];
int dfs_low[MX_N];
stack<int> scc;
int dfsCounter;
int sccCnt;

void tarjans(int u) {
    scc.push(u);
    vis[u] = true;

    dfs_low[u] = dfs_num[u] = dfsCounter++;
    for(int i = 0; i < N; i++){
        if(!adjMat[u][i])
            continue;
        if(dfs_num[i] == 0){
            tarjans(i);
            dfs_low[u] = min(dfs_low[u], dfs_low[i]);
        } else if (vis[i]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[i]);
        }
    }
    if(dfs_low[u]==dfs_num[u]){
        sccCnt++;
        while(1){
            int v = scc.top(); scc.pop();
            vis[v]=false;
            if(v==u)
                break;
        }
    }
}

bool sccCheck(){
    dfsCounter=1;
    sccCnt=0;
    memset(vis,0,sizeof(vis));
    memset(dfs_num,0,sizeof(dfs_num));
    memset(dfs_low,0,sizeof(dfs_low));
    while(!scc.empty())
        scc.pop();
    for(int i = 0; i < N; i++)
        if(dfs_num[i]==0)
            tarjans(0);
    return sccCnt==1;
}


int main(){
    int _t = 1;
    while(scanf("%d %d",&N,&M)==2){
        printf("Case %d: ",_t++);
        int _a,_b;
        vector<ii> eList(M);
        memset(adjMat,0,sizeof(adjMat));
        for(int i = 0; i < M; i++){
            scanf("%d %d",&_a,&_b);
            adjMat[_a][_b]=true;
            eList[i].first=_a;
            eList[i].second=_b;
        }
        if(sccCheck())
            puts("valid");
        else {
            bool s=false;
            for(int i = 0; i < M&&!s; i++){
                int x = eList[i].first;
                int y = eList[i].second;
                adjMat[x][y]=false;
                adjMat[y][x]=true;
                if(sccCheck()){
                    printf("%d %d\n",x,y);
                    s=true;
                }
                adjMat[x][y]=true;
                adjMat[y][x]=false;
            }
            if(!s)
                puts("invalid");
        }
    }
    return 0;
}
