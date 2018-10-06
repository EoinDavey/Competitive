#include<bits/stdc++.h>
using namespace std;
const int MX_N = 10011;
int N,M;
int dfs_counter = 0;
int dfs_num[MX_N], dfs_low[MX_N];
bool vis[MX_N];
vector<int> adjList[MX_N];

void dfs(int u, int p){
    dfs_num[u] = dfs_low[u] = ++dfs_counter;
    for(int v : adjList[u]){
        if(dfs_num[v]==0){
            dfs(v,u);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != p)
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int mark(int u) {
    vis[u] = true;
    int s = 1;
    for(int v : adjList[u]){
        if(!vis[v] && dfs_low[v] <= dfs_num[u])
            s+=mark(v);
    }
    return s;
}

int main(){
    scanf("%d %d", &N, &M);
    int u,v;
    for(int i = 0; i < M; ++i){
        scanf("%d %d", &u, &v);
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    dfs(0,-1);
    int cnt = 0;
    /*puts("dfs_num");
    for_each(dfs_num,dfs_num+N,[](int a){printf("%d ",a);});
    putchar('\n');
    puts("dfs_low");
    for_each(dfs_low,dfs_low+N,[](int a){printf("%d ",a);});
    putchar('\n');*/
    printf("%d\n",mark(0));
    return 0;
}
