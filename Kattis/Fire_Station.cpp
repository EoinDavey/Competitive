#include<bits/stdc++.h>
using namespace std;

struct edge {
    int v,w;
    edge(int _v, int _w) : v(_v), w(_w) {}
    edge(){}
};

struct path {
    int u,d;
    path(int _u, int _d) : u(_u), d(_d) {}
    path(){}
    bool operator < (const path &p) const {
        return d > p.d;
    }
};

constexpr int MX_N = 505,INF=100000000;
vector<edge> adjList[MX_N];
vector<int> fList;
int dist[MX_N];
int N,F;
int f = 0;

int main(){
    ios::sync_with_stdio(false);
    string sin;
    int T; cin >> T;
    while(T-->0){
        cin >> F >> N;
        fList.clear();
        ++N;
        for(int i = 0; i < N; ++i)
            adjList[i].clear();
        int in;
        for(int i= 0; i < F; i++){
            cin >> in;
            fList.push_back(in);
        }
        getline(cin,sin);
        int a,b,w;
        while(1){
            getline(cin,sin);
            if(sin=="")
                break;
            stringstream ss(sin);
            ss >> a >> b >> w;
            adjList[a].push_back(edge(b,w));
            adjList[b].push_back(edge(a,w));
        }
        int u,d;
        int mn = INF;
        int ans = 0;
        for(int k = 1; k < N; ++k){
            for(int i = 0; i < N; ++i)
                dist[i]=INF;
            priority_queue<path> q;
            for(auto i : fList)
                q.push(path(i,0));
            q.push(path(k,0));
            while(!q.empty()){
                path p = q.top(); q.pop();
                u = p.u;
                d = p.d;
                if(dist[u]<=d)
                    continue;
                dist[u] = d;
                for(auto i : adjList[u]){
                    if(d + i.w < dist[i.v])
                        q.push(path(i.v,d+i.w));
                }
            }
            int mx = 0;
            for(int i = 1; i < N; ++i)
                mx = max(mx,dist[i]);
            if(mx < mn){
                mn = mx;
                ans = k;
            }
        }
        printf("%d\n\n",ans);
    }
    return 0;
}
