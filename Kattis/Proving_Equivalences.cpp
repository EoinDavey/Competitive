#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<cstring>
#include<map>

using namespace std;

typedef pair<int, int> ii;

const int MX_N = 20002;
int N,M;
vector<int> adjList[MX_N];
int dfs_num[MX_N],dfs_low[MX_N];
bool vis[MX_N];
stack<int> scc;
int dfsCounter=1;
int sccIdx=1;

map<int, int> sccMap;

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
            if(v==u)
                break;
        }
        sccIdx++;
    }
}

int main(){
    int T; scanf("%d",&T);
    while(T --> 0){
        scanf("%d %d",&N,&M);

        for(int i = 0; i < N; i++){
            adjList[i].clear();
            dfs_num[i]=0;
            dfs_low[i]=0;
            vis[i]=false;
        }
        while(!scc.empty())scc.pop();
        dfsCounter=1;
        sccIdx=1;
        sccMap.clear();

        int x,y;
        vector<ii> eList(M);
        for(int i = 0; i < M; i++){
            scanf("%d %d",&x,&y);
            x--;y--;
            adjList[x].push_back(y);
            eList[i].first=x;
            eList[i].second=y;
        }
        for(int i = 0; i < N; i++)
            if(dfs_num[i]==0)
                tarjans(i);
        bool hasIn[sccIdx+1];
        bool hasOut[sccIdx+1];
        memset(hasIn,0,sizeof(hasIn));
        memset(hasOut,0,sizeof(hasOut));
        for(int i = 0; i < M; i++){
            x = eList[i].first;
            y = eList[i].second;
            if(sccMap[x]!=sccMap[y]){
                hasIn[sccMap[x]]=hasOut[sccMap[y]]=true;
            }
        }
        int noIn = sccIdx-1;
        int noOut = sccIdx-1;
        for(int i = 1; i < sccIdx; i++){
            if(hasIn[i])
                noIn--;
            if(hasOut[i])
                noOut--;
        }
        if(sccIdx>2)
            printf("%d\n",max(noIn,noOut));
        else
            puts("0");
    }
    return 0;
}

