#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef pair<int,int> ii;
const int MX_N = 100010;
const int RT = MX_N - 1;
vector<int> adjList[MX_N];
vector<int> diAdjList[MX_N];
int vis[MX_N];
int leaf[MX_N];
int N, K;

//void pr(int i){for(int j = 0; j < i; ++j)putchar(' ');}
bool check(int u){
    //pr(d);printf("check(%d)\n", u);
    if(diAdjList[u].size() < 3 && diAdjList[u].size()!=0)
        return false;
    for(int v : diAdjList[u]){
        if(!check(v))
            return false;
    }
    return true;
}

int main(){
    scanf("%d %d",&N,&K);
    int x,y;
    for(int i = 0; i < N-1; ++i){
        scanf("%d %d",&x,&y);
        --x,--y;
        adjList[x].pb(y);
        adjList[y].pb(x);
    }
    for(int i = 0; i < N; ++i)
        if(adjList[i].size()==1)
            adjList[RT].pb(i), leaf[i]=true;
    queue<int> q;
    vis[RT] = 1;
    q.push(RT);
    while(!q.empty()){
        int u = q.front();q.pop();
        for(int v : adjList[u]){
            if(!vis[v]){
                vis[v] = vis[u]+1;
                q.push(v);
            }
        }
    }
    int cent = RT;
    for(int i = 0; i < N; ++i)
        if(vis[i] > vis[cent])
            cent=i;
    memset(vis, 0, sizeof(vis));
    q.push(cent);
    vis[cent] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adjList[u]){
            if(!vis[v]){
                vis[v]=vis[u]+1;
                diAdjList[u].pb(v);
                q.push(v);
            }
        }
    }
    bool fail = !check(cent);
    for(int i = 0; i < N; ++i)
        if(diAdjList[i].size()==0 && vis[i] != K+1)
            fail = true;
    if(fail)
        puts("No");
    else
        puts("Yes");
    return 0;
}
