#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int MX_N = 5005;
const int INF = 1000*1000*1000;
int N,H,R;
vector<ii> adjList[MX_N];
vector<ii> revAdjList[MX_N];
map<int,int> rStore;
int dist[MX_N];

struct edge {
    int u,d;
    bool operator<(const edge& e) const {
        if(d!=e.d)
            return d>e.d;
        return u > e.u;
    }
};

int rf(int i){ return rStore.find(i) != rStore.end() ? rStore[i] : i;}

vector<int> order;
void genTop(int u){
    for(auto& v : revAdjList[u])
        if(dist[v.first]+v.second == dist[u])
            genTop(v.first);
    order.push_back(u);
}

int main(){
    scanf("%d %d %d",&N,&H,&R);
    int ni,nj;
    for(int i = 0; i < R; ++i){
        scanf("%d %d", &ni, &nj);
        rStore[ni] = nj;
    }
    for(int i = 1; i <= 5000; ++i){
        // Attack
        adjList[i].push_back({rf(i-1),i});
        revAdjList[rf(i-1)].push_back({i,i});
        //Defend
        adjList[i].push_back({rf(i),1});
        revAdjList[rf(i)].push_back({i,1});
    }
    for(int i = 0; i <= 5000; ++i)
        dist[i] = INF;
    priority_queue<edge> q;
    dist[N] = 0;
    q.push({N,0});
    while(!q.empty()){
        edge u = q.top();q.pop();
        if(dist[u.u] < u.d)
            continue;
        for(auto& v : adjList[u.u]){
            int nd = u.d + v.second;
            if(dist[v.first] > nd){
                dist[v.first] = nd;
                q.push({v.first,nd});
            }
        }
    }
    if(dist[0] < H){
        genTop(0);
        int mDist[MX_N];for(int i = 0; i <= 5000; ++i)mDist[i]=INF;
        mDist[0] = 0;
        for(auto u = order.rbegin(); u != order.rend(); u++){
            for(auto& v : revAdjList[*u])
                if(dist[v.first]+v.second == dist[*u])
                    mDist[v.first] = min(mDist[v.first], 1+mDist[*u]);
        }
        printf("%d\n", mDist[N]);
    }
    else
        puts("retreat");
    return 0;
}
