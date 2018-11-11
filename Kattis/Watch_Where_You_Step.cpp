#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int MX_N = 2505;
vector<int> adjList[MX_N];
int adjMat[MX_N][MX_N];
int sccSz[MX_N];
int sccMat[MX_N][MX_N];
stack<int> scc;
int dfsCounter=1;
int sccIdx=0;
map<int, int> sccMap;
bool vis[MX_N];
int dfs_low[MX_N], dfs_num[MX_N];
int N;

void tarjans(int u){
    scc.push(u);
    vis[u]=true;

    dfs_low[u]=dfs_num[u]=dfsCounter++;

    for(int i = 0; i < adjList[u].size(); i++){
        int v = adjList[u][i];
        if(dfs_num[v]==0){
            tarjans(v);
            dfs_low[u]=min(dfs_low[u],dfs_low[v]);
        } else if(vis[v]){
            dfs_low[u]=min(dfs_low[u],dfs_num[v]);
        }
    }
    if(dfs_low[u]==dfs_num[u]){
        while(1){
            int v = scc.top(); scc.pop();
            sccMap[v]=sccIdx;
            vis[v]=false;
            sccSz[sccIdx]++;
            if(v==u)
                break;
        }
        sccIdx++;
    }
}

int main(){
    scanf("%d",&N);
    for(int i = 0; i < N; ++i){
        for(int j =0; j < N; ++j){
            scanf("%d",&adjMat[i][j]);
            if(adjMat[i][j])
                adjList[i].pb(j);
        }
    }
    for(int i = 0; i < N; ++i)
        if(dfs_num[i]==0)
            tarjans(i);
    int tot = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j) {
            if(i!=j && !adjMat[i][j] && sccMap[i] == sccMap[j])
                ++tot;
            if(adjMat[i][j] && sccMap[i] != sccMap[j])
                sccMat[sccMap[i]][sccMap[j]]++;
        }
    }
    for(int i = 0; i < sccIdx; ++i)
        for(int j = 0; j < i; ++j)
            tot += sccSz[i]*sccSz[j] - sccMat[i][j];
    printf("%d\n", tot);
    return 0;
}
