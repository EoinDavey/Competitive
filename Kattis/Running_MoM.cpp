#include<bits/stdc++.h>
using namespace std;
const int MX_N = 10001;
const int UNVIS=0,VIS=1,EXP=2;
int state[MX_N];
bool safe[MX_N];
map<string,int> idMap;
vector<int> adjList[MX_N];
int idCnt;

bool dfs(int u){
    state[u] = VIS;
    for(int v : adjList[u]){
        if(state[v]==UNVIS)
            safe[u] |= dfs(v);
        else if(state[v]==VIS)
            safe[u] = true;
        else if(state[v]==EXP)
            safe[u] |= safe[v];
    }
    state[u] = EXP;
    return safe[u];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int p; cin >> p;
    string x,y;
    int idx,idy;
    for(int i = 0; i< p; ++i){
        cin >> x >> y;
        if(idMap.count(x) > 0)
            idx = idMap[x];
        else
            idMap[x] = idx = idCnt++;
        
        if(idMap.count(y) > 0)
            idy = idMap[y];
        else
            idMap[y] = idy = idCnt++;
        adjList[idx].push_back(idy);
    }
    for(int i = 0; i < idCnt; ++i)
        if(state[i]==UNVIS)
            dfs(i);
    while(cin >> x){
        cout << x;
        if(safe[idMap[x]])
            cout << " safe";
        else
            cout << " trapped";
        cout << endl;
    }
}
