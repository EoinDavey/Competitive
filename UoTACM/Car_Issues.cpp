#include<bits/stdc++.h>
using namespace std;
const int MX_N = 2002;
vector<int> adjList[MX_N];
vector<int> revAdjList[MX_N];
vector<int> ids;
bool vis[MX_N];
bool trapped[MX_N];
bool unreachable[MX_N];
int N;

int dfs(int u, vector<int> list[]){
    vis[u]=true;
    for(int v : list[u])
        if(!vis[v])
            dfs(v, list);
}

int main(){
    scanf("%d",&N);
    for(int i = 0; i < N; ++i){
        int id, cnt; scanf("%d %d",&id, &cnt);
        ids.push_back(id);
        int v;
        for(int j = 0; j < cnt; ++j){
            scanf("%d",&v);
            adjList[id].push_back(v);
            revAdjList[v].push_back(id);
        }
    }
    bool pr = false;
    dfs(0,revAdjList);
    for(int id : ids)
        if(!vis[id])
            printf("TRAPPED %d\n",id),pr=true;
    memset(vis,0,sizeof(vis));
    dfs(0,adjList);
    for(int id : ids)
        if(!vis[id])
            printf("UNREACHABLE %d\n",id),pr=true;
    if(!pr)
        puts("NO PROBLEMS");
    return 0;
}
