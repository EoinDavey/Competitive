#include<bits/stdc++.h>
using namespace std;

constexpr int MX_N = 1001,INF=100000;
int N,H,L;
int dist[MX_N];
vector<int> adjList[MX_N];

int main(){
    scanf("%d %d %d",&N,&H,&L);
    for(int i = 0; i < N; ++i)
        dist[i]=INF;
    int a,b;
    for(int i = 0; i < H; ++i){
        scanf("%d",&a);
        dist[a]=0;
    }
    for(int i = 0; i < L; ++i){
        scanf("%d %d",&a,&b);
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    queue<int> q;
    for(int i= 0; i < N; i++)
        if(dist[i]==0)
            q.push(i);
    while(!q.empty()){
        int u = q.front(); q.pop();
        int d = dist[u];
        for(auto i : adjList[u]){
            if(dist[i]==INF){
                dist[i]=d+1;
                q.push(i);
            }
        }
    }
    int mx = 0;
    for(int i = 0; i < N; ++i)
        mx = max(mx,dist[i]);
    for(int i = 0; i < N; ++i){
        if(dist[i]==mx){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
