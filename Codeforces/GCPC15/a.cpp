#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int MX_N = 20002;
const int MX_P = 15;
const int INF = 1000*1000*1000;
typedef pair<int, int> ii;
struct node{
    int u, w;
    bool operator<(const node& n) const {
        if(w != n.w)
            return w > n.w;
        return u < n.u;
    }
};

vector<ii> adjList[MX_N];
int N,P,M,G,T;
int p[MX_P];
int wt[MX_P];
int pdist[MX_P][MX_N];
int dist[MX_N];
int memo[1<<MX_P][MX_P][2];

int dijk(int s){
    for(int i = 0; i < N; ++i)
        dist[i] = INF;
    dist[p[s]] = 0;
    priority_queue<node> q;
    q.push({p[s],0});
    while(!q.empty()){
        node u = q.top();q.pop();
        if(dist[u.u] < u.w)
            continue;
        for(const ii& v : adjList[u.u]){
            if(dist[v.fi] > v.se + u.w){
                dist[v.fi] = v.se + u.w;
                q.push({v.fi, v.se+u.w});
            }
        }
    }
    for(int i = 0; i < N; ++i)
        pdist[s][i] = dist[i];
}

int dp(int state, int cur, bool taxi){
    if(state==(1<<P)-1)
        return pdist[cur][0];
    if(memo[state][cur][taxi] != -1)
        return memo[state][cur][taxi];
    int mn = INF;
    for(int i = 0; i < P; ++i){
        if((state&(1<<i))!=0)
            continue;
        mn = min(mn, pdist[cur][p[i]] + dp(state | (1<<i), i, taxi));
        if(taxi)
            mn = min(mn, dp(state | (1<<i), i, !taxi) + T);
    }
    return memo[state][cur][taxi] = mn;
}

int main(){
    memset(memo,-1,sizeof(memo));
    scanf("%d %d %d %d %d", &N, &P, &M, &G, &T);
    int w;
    for(int i = 0; i < P; ++i){
        scanf("%d %d", &p[i], &w);
        G-=w;
    }
    int si,di,ti;
    for(int i = 0; i < M; ++i){
        scanf("%d %d %d", &si, &di, &ti);
        adjList[si].push_back({di,ti});
        adjList[di].push_back({si,ti});
    }
    for(int i = 0; i < P; ++i)
        dijk(i);
    int mn = INF;
    for(int i = 0; i< P; ++i)
        mn = min(mn, pdist[i][0] + dp(0,i,false));
    if(mn <= G){
        puts("possible without taxi");
        return 0;
    }
    mn = INF;
    for(int i = 0; i< P; ++i)
        mn = min(mn, pdist[i][0] + dp(0, i, true));
    if(mn <= G){
        puts("possible with taxi");
        return 0;
    }
    puts("impossible");
    return 0;
}
