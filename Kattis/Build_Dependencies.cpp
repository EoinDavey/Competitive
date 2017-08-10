#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

unordered_map<string,vector<string> > adjList;
unordered_map<string,bool> vis;
vector<string> topSort;

void dfs(string u){
    vis[u]=true;
    for(int i = 0; i < adjList[u].size(); i++)
        if(!vis[adjList[u][i]])
            dfs(adjList[u][i]);
    topSort.push_back(u);
}

int main(){
    ios::sync_with_stdio(false);
    int N; cin >> N;
    string in, root;
    getline(cin,in);
    for(int i = 0; i < N; i++){
        getline(cin,in);
        stringstream ss(in);
        ss >> root;
        root = root.substr(0,root.size()-1);
        while(ss >> in){
            adjList[in].push_back(root);
        }
    }
    cin >> in;
    dfs(in);
    for(int i = topSort.size()-1; i >=0; i--)
        cout << topSort[i]<<endl;
    return 0;
}
