#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

int N, R;
int deg[222];
bool vis[222];
vector<int> adjList[222];

void fill(int u){
    vis[u] = true;
    for(int i = 0; i < adjList[u].size(); i++){
        if(!vis[adjList[u][i]])
            fill(adjList[u][i]);
    }
}

int main(){
    while(cin >> N >> R){
        if(R==0){
            cout << "Not Possible\n";
            continue;
        }
        memset(deg,0,sizeof(deg));
        memset(vis,false,sizeof(vis));
        int ix,iy;
        for(int i= 0; i < N; i++){
            adjList[i].clear();
        }
        for(int i = 0; i < R; i++){
            scanf("%d %d",&ix,&iy);
            deg[ix]++;
            deg[iy]++;
            adjList[ix].push_back(iy);
            adjList[iy].push_back(ix);
        }
        if(R>0)fill(ix);
        bool filled = true;
        int n_odd = 0;
        for(int i = 0; i < N;i++){
            if(deg[i] % 2 == 1)
                n_odd++;
            if(deg[i] > 0 && !vis[i])
                filled = false;
        }
        if(n_odd > 0 || !filled)
            cout << "Not Possible\n";
        else cout << "Possible\n";
    }
    return 0;
}
