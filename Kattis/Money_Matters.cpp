#include<bits/stdc++.h>
using namespace std;

const int MX_N=10011;
vector<int> adjList[MX_N];
int N,M;
int c[MX_N];
bool vis[MX_N];

int dfs(int u){
    vis[u]=true;
    int sm = c[u];
    for(auto i = adjList[u].begin(); i != adjList[u].end(); i++){
        if(!vis[*i])
            sm+=dfs(*i);
    }
    return sm;
}

int main(){
    scanf("%d %d",&N,&M);
    for(int i = 0; i < N; i++)
        scanf("%d",&c[i]);
    int a,b;
    for(int j = 0; j < M; j++){
        scanf("%d %d",&a,&b);
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    bool fail = false;
    for(int i = 0; i < N && !fail; i++)
        fail |= !vis[i] && (dfs(i)!=0);
    if(fail)
        puts("IMPOSSIBLE");
    else
        puts("POSSIBLE");
    return 0;
}
