#include<bits/stdc++.h>
using namespace std;

const int MX_N=111;
int N,dfs_low[MX_N],dfs_num[MX_N];
unordered_map<string,vector<int> > langList;
vector<int> adjList[MX_N];
int dfsCounter=1,idx=1,mxScc=0;
stack<int> scc;
bool vis[MX_N];
string speaks[MX_N];

void tarjans(int u){
    scc.push(u);
    dfs_num[u]=dfs_low[u]=dfsCounter++;
    vis[u]=true;
    
    for(auto i = adjList[u].begin(); i != adjList[u].end(); i++){
        if(dfs_num[*i]==0){
            tarjans(*i);
            dfs_low[u]=min(dfs_low[u],dfs_low[*i]);
        } else if (vis[*i]){
            dfs_low[u]=min(dfs_low[u],dfs_num[*i]);
        }
    }

    int sz=0;
    if(dfs_low[u]==dfs_num[u]){
        while(1){
            int v = scc.top(); scc.pop();
            vis[v]=false;
            sz++;
            if(v==u)
                break;
        }
    }
    mxScc=max(sz,mxScc);
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    string in;
    getline(cin,in);
    for(int i = 0;i < N; i++){
        getline(cin,in);
        stringstream ss(in);
        ss >> in;
        ss >> speaks[i];
        langList[speaks[i]].push_back(i);
        while(ss >> in)
            langList[in].push_back(i);
    }
    for(int i = 0; i < N; i++)
        for(auto j = langList[speaks[i]].begin(); j != langList[speaks[i]].end(); j++)
            adjList[i].push_back(*j);
    for(int i = 0; i < N; i++)
        if(dfs_num[i]==0)
            tarjans(i);
    cout << N-mxScc << endl;
    return 0;
}
