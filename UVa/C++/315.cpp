#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<vector>
#include<cstring>

using namespace std;

int N;
vector<int> adjList[111];
int dfs_num[111];
int dfs_low[111];
int dfs_parent[111];
int dfs_counter = 0;
bool artP[111];
int rChildren = 0;
int artCount = 0;
int dfs_root = 0;

void dfs(int pos){
    dfs_num[pos] = dfs_low[pos] = dfs_counter++;
    bool art = false;
    for(int i = 0; i < adjList[pos].size(); i++){
        int v = adjList[pos][i];
        if(dfs_num[v] == -1){
            dfs_parent[v] = pos;
            if(pos == dfs_root) rChildren++;
            dfs(v);
            if(dfs_low[v] >= dfs_num[pos])
                artP[pos] = true;
            dfs_low[pos] = min(dfs_low[pos], dfs_low[v]);
        } else if(dfs_parent[pos] != v)
            dfs_low[pos] = min(dfs_low[pos], dfs_num[v]);
    }
}

int main(){
    while(cin >> N){
        if(N==0) break;
        N++;
        int ti,tj;
        string is;
        memset(dfs_num,-1,sizeof(dfs_num));
        memset(dfs_low,0,sizeof(dfs_low));
        memset(dfs_parent,0,sizeof(dfs_low));
        memset(artP,false,sizeof(artP));
        dfs_counter=artCount=rChildren=dfs_root=0;
        for(int i = 0; i < N; i++)
            adjList[i].clear();
        getline(cin,is);
        while(true){
            getline(cin,is);
            stringstream ss(is);
            ss >> ti;
            if(ti==0) break;
            while(ss >> tj){
                adjList[ti].push_back(tj);
                adjList[tj].push_back(ti);
            }
        }
        for(int i = 1; i < N; i++){
            if(dfs_num[i]==-1){
                rChildren = 0;
                dfs_root = i;
                dfs(i);
                artP[i] = (rChildren > 1);
            }
        }
        for(int i = 1; i < N; i++)
            if(artP[i])artCount++;
        cout << artCount << endl;
    }
    return 0;
}
