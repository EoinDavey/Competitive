#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int MX_N = 27;
vector<int> adjList[MX_N];
int N, M;
int scrs[MX_N][MX_N];
int vis;

void dfs(int u){
    vis|=(1<<u);
    for(int v : adjList[u])
        if((vis&(1<<v))==0)
            dfs(v);
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; ++i){
        int x;
        string s;
        cin >> x >> s;
        for(int i = 0; i < s.size(); ++i){
            for(int j = 0; j < i; ++j){
                scrs[s[i]-'A'][s[j]-'A']+=x;
            }
        }
    }
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < i; ++j){
            if(scrs[i][j] > scrs[j][i])
                adjList[j].pb(i);
            else
                adjList[i].pb(j);
        }
    }
    for(int i = 0; i < N; ++i){
        vis = 0;
        dfs(i);
        if(vis==(1<<N)-1)
            printf("%c: can win\n",i+'A');
        else
            printf("%c: can't win\n",i+'A');
    }
    return 0;
}
