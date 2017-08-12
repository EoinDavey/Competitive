#include<iostream>
#include<cstdio>
#include<sstream>
#include<string>
#include<vector>
#include<map>

using namespace std;

int N;
string dest,root;
map<string,vector<string>> adjMap;
map<string,bool> vis;
vector<string> out;

bool dfs(string node){
    if(node==dest){
        out.push_back(node);
        return true;
    }
    vis[node]=true;
    for(auto i = adjMap[node].begin(); i!=adjMap[node].end();i++){
        if(!vis[*i]){
            if(dfs(*i)){
                out.push_back(node);
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    getline(cin,root);
    for(int i =0; i < N; i++){
        getline(cin,root);
        stringstream ss(root);
        ss >> root;
        while(ss >> dest){
            adjMap[root].push_back(dest);
            adjMap[dest].push_back(root);
        }
    }
    cin >> root >> dest;
    if(dfs(root)){
        for(int i = out.size()-1; i >=0; i--){
            cout << out[i];
            if(i>0)
                cout << " ";
        }
        cout << endl;
    } else
        puts("no route found");
    return 0;
}
