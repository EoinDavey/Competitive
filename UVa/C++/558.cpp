#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define ii pair<int,int>

using namespace std;

const int MX_N = 2222;
const int INF = 1000000000;
vector<ii> adjList[MX_N];
int N,M;

int main(){
    int C;scanf("%d",&C);
    for(int _c = 0; _c < C; _c++){
        scanf("%d %d",&N,&M);
        for(int i= 0; i < N; i++)
            adjList[i].clear();
        int x,y,t;
        for(int i = 0; i< M; i++){
            scanf("%d %d %d",&x,&y,&t);
            adjList[x].push_back(make_pair(y,t));
        }
        // Bellman Ford
        int dist[N];
        for(int i =1;  i < N; i++)
            dist[i]=INF;
        dist[0]=0;
        bool modified = false;
        for(int k = 0; k < N-1; k++){
            modified=false;
            for(int i = 0; i < N; i++)
                for(int j = 0; j < adjList[i].size(); j++){
                    ii p = adjList[i][j];
                    if(dist[i]+p.second < dist[p.first]){
                        dist[p.first]=dist[i]+p.second;
                        modified=true;
                    }
                }
            if(!modified)
                break;
        }
        for(int i = 0; i < N; i++)
            for(int j = 0; j < adjList[i].size(); j++){
                ii p = adjList[i][j];
                if(dist[i]+p.second < dist[p.first])
                    modified=true;
            }
        if(modified)
            puts("possible");
        else
            puts("not possible");
    }
    return 0;
}
