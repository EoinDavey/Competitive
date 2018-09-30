#include<bits/stdc++.h>
using namespace std;
const int MX_N = 10011;
vector<int> adjList[MX_N];
int N,M;
int c[MX_N];

void dfs(int u, int col){
    c[u] = col;
    for(int v : adjList[u])
        if(c[v]==-1)
            dfs(v,1-col);
}

int main(){
    scanf("%d %d",&N,&M);
    memset(c,-1,sizeof(c));
    int x,y;
    for(int i =0; i < M; ++i){
        scanf("%d %d",&x,&y);
        --x;--y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    for(int i = 0; i < N; ++i)
        if(c[i]==-1)
            dfs(i,0);
    bool valid = true;
    for(int i = 0; i < N && valid; ++i){
        int safe = false;
        for(int v : adjList[i])
            if(c[v]==1-c[i])
                safe=true;
        if(!safe)
            valid = false;
    }
    if(!valid)
        puts("Impossible");
    else{
        for(int i = 0; i < N; ++i)
            if(c[i]==1)
                printf("pub ");
            else
                printf("house ");
        putchar('\n');
    }
    return 0;
}
