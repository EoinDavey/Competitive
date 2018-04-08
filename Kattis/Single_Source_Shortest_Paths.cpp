#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> ii;

struct path {
    int u,d;
    path(int _u, int _d) : u(_u), d(_d) {}
    path(){}
    bool operator < (const path& p) const {
        return d > p.d;
    }
};

constexpr int MX_N=10001,MX_M=30003,MX_Q=101,INF=1000000000;
int N,M,Q,S;
int dist[MX_N];
vector<ii> adjList[MX_N];

inline int read_int(){
    int o = 0; char c;
    while(1){
        c = getchar_unlocked();
        if(c>='0' && c <= '9')
            break;
    }
    do {
        o = o*10 + c - '0';
        c = getchar_unlocked();
    }while(c>='0' && c <= '9');
    return o;
}

int main(){
    while(1){
        N=read_int();
        M=read_int();
        Q=read_int();
        S=read_int();
        if(!(N | M | Q | S))
            break;
        int u,v,w,d,nd;
        for(int i =0; i < N; ++i){
            dist[i] = INF;
            adjList[i].clear();
        }
        for(int i = 0; i < M; ++i){
            u = read_int();
            v=read_int();
            w=read_int();
            adjList[u].push_back({v,w});
        }
        dist[S] = 0;
        priority_queue<path> q;
        q.push(path(S,0));
        while(!q.empty()){
            path p = q.top(); q.pop();
            u = p.u,d = p.d;
            if(dist[u] < d)
                continue;
            for(auto i = adjList[u].begin(); i != adjList[u].end(); i++){
                nd = d + i->second;
                if(nd < dist[i->first]){
                    dist[i->first] = nd;
                    q.push(path(i->first,nd));
                }
            }
        }
        for(int i = 0; i < Q; ++i){
            u=read_int();
            if(dist[u] == INF)
                puts("Impossible");
            else
                printf("%d\n",dist[u]);
        }
        putchar_unlocked('\n');
    }
    return 0;
}
