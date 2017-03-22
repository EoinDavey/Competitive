#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

int N,M;
vector<int> adjList[1111];
int dfs_num[1111], dfs_low[1111], dfs_state[1111];
int UNEXPLORED = -1, EXPLORED = 1, VISITED = 2;
int dfs_parent[1111];
int root = 0, rChildren = 0;
int dfs_counter = 0;

void bridgeF(int u){
    dfs_num[u] = dfs_low[u] = ++dfs_counter;
    dfs_state[u] = VISITED;
    if(dfs_parent[u] == root)
        rChildren++;
    for(int i = 0; i < adjList[u].size(); i++){
        int v = adjList[u][i];
        if(dfs_num[v]==UNEXPLORED){
            dfs_parent[v] = u;
            printf("%d %d\n",u,v);
            bridgeF(v);
            if(dfs_low[v] > dfs_num[u]){
                printf("%d %d\n",v,u);
            }
            dfs_low[u] = min(dfs_low[u],dfs_low[v]);
        } else if (v != dfs_parent[u]){
            if(dfs_state[v] == VISITED)
                printf("%d %d\n",u,v);
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
    dfs_state[u] = EXPLORED;
}

int main(){
    int cnt = 0;
    while(true){
        cin >> N >> M;
        if(N==0 && M==0)
            break;
        int ii,ij;
        for(int i = 0; i <= N; i++)
            adjList[i].clear();
        for(int i = 0; i < M; i++){
            scanf("%d %d",&ii,&ij);
            adjList[ii].push_back(ij);
            adjList[ij].push_back(ii);
        }
        rChildren = 0;
        memset(dfs_num,-1,sizeof(dfs_num));
        memset(dfs_low,-1,sizeof(dfs_low));
        memset(dfs_parent, -1, sizeof(dfs_parent));
        memset(dfs_state, UNEXPLORED, sizeof(dfs_state));
        root = 1;
        printf("%d\n\n",++cnt);
        bridgeF(1);
        printf("#\n");
    }
    return 0;
}
