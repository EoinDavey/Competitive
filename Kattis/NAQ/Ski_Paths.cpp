#include<bits/stdc++.h>
using namespace std;
const int MX_N = 250002;
vector<int> adjList[MX_N];
set<int> skiList[MX_N];
bool start[MX_N], endV[MX_N], monitor[MX_N], vis[MX_N];
int N,K,M;

bool pullUp(int u){
    for(int v : adjList[u]){
        if(!vis[v]
    }
}

int main(){
    scanf("%d %d %d", &N, &K ,&M);
    int u,v;
    for(int i = 0; i < K;++i){
        scanf("%d %d", &u, &v);
        --u,--v;
        adjList[u].push_back(v);
    }
    for(int i =0; i < M; ++i){
        scanf("%d %d",&u,&v);
        --u,--v;
        start[u]=true;
        endV[v]=true;
    }
    for(int i = 0; i < N; ++i)
        if(!vis[i])
            trav(i);
    return 0;
}
