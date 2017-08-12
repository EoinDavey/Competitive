#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;

struct edge {
    int x; double f;
    edge(int _x, double _f):x(_x),f(_f){}
    bool operator < (edge p) const {
        return f > p.f;
    }
};

const int MX_N=10001;
const int MX_M=15001;
int N,M;
double dist[MX_N];
vector<edge> adjList[MX_N];

int main(){
    while(scanf("%d %d",&N,&M),N||M){
        for(int i = 0; i < N; i++){
            adjList[i].clear();
            dist[i]=1.0;
        }
        int x,y; double f;
        for(int i = 0; i < M; i++){
            scanf("%d %d %lf",&x,&y,&f);
            adjList[x].push_back(edge(y,f));
            adjList[y].push_back(edge(x,f));
        }
        priority_queue<edge> q;
        q.push(edge(0,0.0));
        while(!q.empty()){
            edge p = q.top(); q.pop();
            x = p.x; f=p.f;
            if(dist[x] <= f)
                continue;
            dist[x]=f;
            for(auto i = adjList[x].begin(); i != adjList[x].end(); i++){
                int nx = i->x;
                double nf = 1.0-((1.0-f)*i->f);
                if(dist[nx] > nf)
                    q.push(edge(nx,nf));
            }
        }
        printf("%.4lf\n", (1.0-dist[N-1]));
    }
    return 0;
}
