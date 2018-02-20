#include<bits/stdc++.h>
using namespace std;
constexpr int MX_N = 202;
typedef pair<int,int> ii;

bool adjMat[MX_N][MX_N];
vector<int> adjList[MX_N];
vector<ii> eList;
bool vis[MX_N];

int N;

inline ii bfsF(int s){
    memset(vis,0,sizeof(vis));
    int u = s;
    int md = 0;
    queue<ii> q;
    q.push({u,md});
    vis[u]=true;
    while(!q.empty()){
        ii p = q.front(); q.pop();
        u = p.first;
        md = p.second;
        for(auto v : adjList[u]){
            if(!adjMat[u][v])
                continue;
            if(!vis[v]){
                vis[v]=true;
                q.push({v,md+1});
            }
        }
    }
    return {u,md};
}

inline int diam(int s){
    ii o = bfsF(s);
    o = bfsF(o.first);
    return o.second;
}

int main(){
    scanf("%d",&N);
    int a,b;
    for(int i = 0; i < N-1; ++i){
        scanf("%d %d",&a,&b);
        --a;--b;
        adjMat[a][b] = adjMat[b][a] = true;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
        eList.push_back({a,b});
    }
    int mx = 0;
    for(auto &p : eList){
        a = p.first; b = p.second;
        adjMat[a][b] = adjMat[b][a] = false;
        mx = max(mx,diam(a)*diam(b));
        adjMat[a][b] = adjMat[b][a] = true;
    }
    printf("%d\n",mx);
    return 0;
}
