#include<bits/stdc++.h>
using namespace std;
const int MX_N = 101;
vector<int> adjList[MX_N];
int N;
int dfs_num[MX_N],dfs_low[MX_N];
int dfs_counter;
bool bridge;

int dfs(int u,int p){
    dfs_num[u] = dfs_low[u] = ++dfs_counter;
    for(auto v : adjList[u]){
        if(dfs_num[v]==0){
            dfs(v,u);
            if(dfs_low[v] > dfs_num[u])
                bridge = true;
            dfs_low[u] = min(dfs_low[u],dfs_low[v]);
        } else if(v!=p)
            dfs_low[u] = min(dfs_low[u],dfs_num[v]);
    }
}

int main(){
    int P,x,y;
    while(scanf("%d %d",&N,&P),N||P){
        for(int i = 0; i < N; ++i)
            adjList[i].clear();
        memset(dfs_num,0,sizeof(dfs_num));
        memset(dfs_low,0,sizeof(dfs_low));
        bridge=false;
        dfs_counter=0;
        for(int i = 0; i < P; ++i){
            scanf("%d %d",&x,&y);
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
        dfs(0,-1);
        for(int i = 0; i < N; ++i)
            if(dfs_num[i]==0)
                bridge=true;
        puts(bridge ? "Yes" : "No");
    }
    return 0;
}
