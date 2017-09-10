#include<bits/stdc++.h>
using namespace std;

constexpr int MX_N = 10000;
vector<int> adjList[MX_N];
int N;
int mnind = 1;
int p[MX_N][2];

void dfs(int u, int par){
    if(adjList[u].size() <= 1 && par != -1){
        p[u][1] = p[par][0];
        p[u][0] = p[par][1];
        return;
    }
    for(int i : adjList[u]){
        if(i!=par){
            if(p[u][0]==0){
                p[u][0] = mnind;
                p[i][0] = mnind++;
            }else if(p[u][1]==0){
                p[u][1] = mnind;
                p[i][0] = mnind++;
            } else {
                p[i][1] = p[u][0];
            }
            dfs(i,u);
        }
    }
}

int main(){
    scanf("%d",&N);
    int a,b;
    for(int i = 0; i < N-1; i++){
        scanf("%d %d",&a,&b);
        --a,--b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    dfs(0,-1);
    for(int i = 0; i < N; i++)
        printf("%d %d\n",p[i][0],p[i][1]);
    return 0;
}
