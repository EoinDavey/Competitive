#include<bits/stdc++.h>
#define BTIND(x) x+1
#define NTIND(x) x+MX_N

using namespace std;

const int MX_N = 505;
int bolts, nuts;
int res[2*MX_N][2*MX_N];
vector<int> adjList[2*MX_N];
bool vis[2*MX_N];
const int S = 0;
const int T = 2*MX_N-1;
const int INF = 1000*1000;

int f = 0;

int ff(int u, int minE){
    if(u==T)
        return minE;
    vis[u] = true;
    for(int v : adjList[u]){
        if(!vis[v] && res[u][v] > 0){
            if(int f = ff(v, min(minE, res[u][v]))){
                res[u][v] -=f;
                res[v][u] +=f;
                return f;
            }
        }
    }
    return 0;
}

int main(){
    int N;
    cin >> N;
    for(int cnt = 1; cnt <= N; ++cnt){
        for(int i = 0; i < T; i++)
            adjList[i].clear();
        for(int i = 0; i < 2*MX_N; ++i)
           for(int j = 0; j <2*MX_N; ++j)
               res[i][j]=0;

        cin >> bolts >> nuts;

        int b;
        for(int i = 0; i < bolts; i++){
            for(int j = 0; j < nuts; j++){
                scanf("%d",&b);
                if(b){
                    adjList[BTIND(i)].push_back(NTIND(j));
                    adjList[NTIND(j)].push_back(BTIND(i));
                    res[BTIND(i)][NTIND(j)] = 1;
                }
            }
        }
        for(int i = 0; i < bolts; ++i){
            res[S][BTIND(i)] = 1;
            adjList[S].push_back(BTIND(i));
            adjList[BTIND(i)].push_back(S);
        }
        for(int i = 0; i < nuts; i++){
            res[NTIND(i)][T] = 1;
            adjList[NTIND(i)].push_back(T);
            adjList[T].push_back(NTIND(i));
        }
        int mf = 0;
        for(;;){
            memset(vis, 0, sizeof(vis));
            int f = ff(S, INF);
            if(f==0)
                break;
            mf+=f;
        }
        printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",cnt,mf);
    }
    return 0;
}
