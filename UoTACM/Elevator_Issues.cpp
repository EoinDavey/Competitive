#include<bits/stdc++.h>
using namespace std;
const int MX_N = 1000*1000+10;
const int INF = 1000*1000*1000;
int F,S,G,U,D;
int dist[MX_N];
struct path {
    int u,w;
    bool operator<(const path& p) const {
        if(w != p.w)
            return w > p.w;
        return u < p.u;
    }
};

int main(){
    scanf("%d %d %d %d %d",&F,&S,&G,&U,&D);
    for(int i = 1; i <= F; ++i)
        dist[i]=INF;
    dist[S]=0;
    priority_queue<path> q;
    q.push({S,0});
    while(!q.empty()){
        path p = q.top();q.pop();
        if(dist[p.u] < p.w)
            continue;
        int nf = p.u+U;
        if(nf <= F && dist[nf] > p.w+1){
            dist[nf] = p.w+1;
            q.push({nf,p.w+1});
        }
        nf = p.u-D;
        if(nf >= 1 && dist[nf] > p.w+1){
            dist[nf] = p.w+1;
            q.push({nf,p.w+1});
        }
    }
    if(dist[G] < INF)
        printf("%d\n", dist[G]);
    else
        puts("use the stairs");
    return 0;
}
