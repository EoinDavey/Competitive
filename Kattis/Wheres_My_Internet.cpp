#include<bits/stdc++.h>
using namespace std;
const int MX_N = 200002;
vector<int> adjList[MX_N];
bool vis[MX_N];

void dfs(int u){
    vis[u]=true;
    for(auto v : adjList[u])
        if(!vis[v])
            dfs(v);
}

int main(){
    int N,M;scanf("%d %d",&N,&M);
    int x,y;
    for(int i = 0; i < M; ++i){
        scanf("%d %d",&x,&y);
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    dfs(1);
    int cnt= 0;
    for(int i = 1; i<=N;++i)
        if(!vis[i])
            printf("%d\n",i),cnt++;
    if(cnt==0)
        puts("Connected");
    return 0;
}
