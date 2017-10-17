#include<bits/stdc++.h>
using namespace std;
constexpr int MX_N = 100001, INF=1000000000;
vector<int> adjList[MX_N];
vector<int> szs;
bool vis[MX_N];
bool vis2[MX_N];
int dist[MX_N];
int N,L;
int mxDm = 0;

void proc(int x){
    queue<int> q;
    q.push(x);
    vis2[x]=true;
    int ls = x;
    while(!q.empty()){
        int u = q.front();q.pop();
        for(auto v : adjList[u]){
            if(!vis2[v]){
                vis2[v]=true;
                q.push(v);
            }
        }
        ls = u;
    }
    x = ls;
    q.push(x);
    dist[x]=0;
    while(!q.empty()){
        int u = q.front();q.pop();
        vis[u]=true;
        for(auto v : adjList[u]){
            if(dist[v]==INF){
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
        ls = u;
    }
    mxDm = max(mxDm,dist[ls]);
    szs.push_back(((int) ceil((1.0*dist[ls]/2))));
}

int main(){
    scanf("%d %d",&N,&L);
    int a,b;
    for(int i = 0; i < N; ++i)
        dist[i]=INF;
    for(int i =0; i < L; ++i){
        scanf("%d %d",&a,&b);
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    for(int i = 0; i < N; ++i)
        if(!vis[i])
            proc(i);
    sort(szs.begin(),szs.end(),greater<int>());
    int mx = mxDm;
    if(szs.size() > 1)
        mx = max(mx, szs[0]+szs[1]+1);
    if(szs.size() > 2)
        mx = max(mx, szs[1]+szs[2]+2);
    printf("%d\n",mx);
    return 0;
}
