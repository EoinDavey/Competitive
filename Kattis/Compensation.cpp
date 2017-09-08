#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

struct train {
    int dep,arr,del;
    train(int _dep, int _arr,int _del) : dep(_dep), arr(_arr), del(_del) {}
    train(){}
};

struct state {
    int st,tm;
    state(int _st, int _tm) : st(_st), tm(_tm) {}
};

struct path {
    int st,tm;
    path(int _st, int _tm) : st(_st), tm(_tm) {}
    bool operator < (const path &p) const {
        return tm > tm;
    }
};

constexpr int MX_N=111, MX_M = 100010, INF=200000;
int N,M;
//map<int> dist[MX_N];
int dist[MX_N];

vector<train> tList[MX_N];

int main(){
    scanf("%d %d",&N,&M);
    int X,S,T,L;
    for(int i = 0; i < M; ++i){
        scanf("%d %d %d %d",&X,&S,&T,&L);
        tList[X-1].push_back(train(S,T,L));
    }
    for(int i = 0; i < N; i++)
        dist[i] = INF;
    priority_queue<path> q;
    q.push(path(0,0));
    int st,tm;
    while(!q.empty()){
        path p = q.top(); q.pop();
        st = p.st; tm = p.tm;
        if(dist[st] <= tm)
            continue;
        dist[st] = tm;
        for(auto t : tList[st]){
            if(t.dep < tm || dist[st+1] <= t.arr)
                continue;
            q.push(path(st+1,t.arr));
        }
    }
    return 0;
}
