#include<bits/stdc++.h>
using namespace std;
const int MX_N = 2020;
const int INF = 1000*1000;
const int S = 0;
const int T = MX_N-1;
int res[MX_N][MX_N];
bool vis[MX_N];
vector<int> adjList[MX_N];
inline int iv(int i){return i+1;}
inline int ov(int i){return i+1012;}

int ff(int u, int minE){
    if(u==T)
        return minE;
    vis[u] = true;
    for(int v : adjList[u])
        if(!vis[v] && res[u][v] > 0)
            if(int f = ff(v, min(minE, min(minE, res[u][v])))){
                res[u][v] -=f;
                res[v][u] +=f;
                return f;
            }
    return 0;
}

int main(){
    int N; scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        int a = iv(i);
        adjList[a].push_back(S);
        adjList[S].push_back(a);
        res[S][a] = 1;
        a = ov(i);
        adjList[a].push_back(T);
        adjList[T].push_back(a);
        res[a][T] = 1;
        int k; scanf("%d", &k);
        int d;
        while(k-->0){
            scanf("%d", &d);
            adjList[iv(i)].push_back(ov(d));
            adjList[ov(d)].push_back(iv(i));
            res[iv(i)][ov(d)]=1;
        }
    }
    int mf = 0;
    for(;;){
        memset(vis,0,sizeof(vis));
        int f = ff(S,INF);
        if(f==0)
            break;
        mf+=f;
    }
    printf("%d\n", N-mf);
    return 0;
}
