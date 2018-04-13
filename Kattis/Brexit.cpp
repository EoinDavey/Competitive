#include<bits/stdc++.h>
using namespace std;
const int MX_N = 200002;
vector<int> adjList[MX_N];
int nCount[MX_N];
bool out[MX_N];
int C,P,X,L;

int main(){
    scanf("%d %d %d %d",&C,&P,&X,&L);
    int a,b;
    for(int i = 0; i < P; ++i){
        scanf("%d %d",&a,&b);
        adjList[a].push_back(b);
        nCount[a]++;
        adjList[b].push_back(a);
        nCount[b]++;
    }
    queue<int> q;
    q.push(L);
    while(!q.empty()){
        int u = q.front();q.pop();
        if(out[u])
            continue;
        out[u] = true;
        for(int v : adjList[u]){
            if(out[v])
                continue;
            nCount[v]--;
            if(nCount[v]*2 <= adjList[v].size())
                q.push(v);
        }
    }
    if(out[X])
        puts("leave");
    else
        puts("stay");
    return 0;
}
