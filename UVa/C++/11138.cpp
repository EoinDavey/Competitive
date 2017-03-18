#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

int bolts, nuts;
int adjMat[1010][1010];
vector<int> adjList[1500];
int s = 0;
int t;
vector<int> p;
int f = 0;
int INF = 1000000;

void augment(int u, int mEdge){
    if(u==s){
        f = mEdge;
        return;
    } else if(p[u]!=-1){
        augment(p[u], min(mEdge, adjMat[p[u]][u]));
        if(adjMat[p[u]][u] == 0)
            adjList[p[u]].push_back(u);
        if(adjMat[u][p[u]] == 0)
            adjList[u].push_back(p[u]);
        adjMat[p[u]][u]-=f;
        adjMat[u][p[u]]+=f;
    }
}

int main(){
    int N,cnt;
    cin >> N;
    for(cnt = 0; cnt < N; cnt++){
        cin >> bolts >> nuts;
        t = bolts+nuts+1;
        for(int i = 0; i <= t; i++)
            adjList[i].clear();
        for(int i = 0; i < bolts; i++){
            for(int j = 0; j < nuts; j++){
                scanf("%d",&adjMat[i+1][j+bolts+1]);
                if(adjMat[i+1][j+bolts+1]){
                    adjList[i+1].push_back(j+bolts+1);
                }
            }
        }
        for(int i = 1; i <= bolts; i++){
            adjMat[s][i] = 1;
            adjList[s].push_back(i);
        }
        for(int i = bolts+1; i < t; i++){
            adjMat[i][t] = 1;
            adjList[i].push_back(t);
        }
        vector<int> dist;
        int mf = 0;
        while(1){
            f = 0;
            dist.assign(t+1,INF);
            p.assign(t+1,-1);
            dist[s] = 0;
            queue<int> q;
            q.push(s);
            while(!q.empty()){
                int u = q.front(); q.pop();
                if(u==t)
                    break;
                for(int i = 0; i < adjList[u].size(); i++){
                    int v = adjList[u][i];
                    if(dist[v]==INF && adjMat[u][v] > 0){
                        dist[v] = dist[u] + 1;
                        p[v] = u;
                        q.push(v);
                    }
                }
            }
            augment(t,INF);
            if(f==0)
                break;
            mf+=f;
        }
        printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",cnt+1,mf);
    }
    return 0;
}
