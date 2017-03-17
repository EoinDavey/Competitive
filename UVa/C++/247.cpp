#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cstring>

using namespace std;

int N, M;
bool adjMat[30][30];
vector<string> names;
map<string, int> vals;

vector<int> S;

int dfs_num[30];
int dfs_low[30];
bool dfs_visited[30];
int dfs_counter;

void dfs(int u){
    dfs_num[u] = dfs_low[u] = dfs_counter++;
    S.push_back(u);
    dfs_visited[u] = true;
    for(int v = 0; v < N; v++){
        if(!adjMat[u][v])continue;
        if(dfs_num[v]==-1)
            dfs(v);
        if(dfs_visited[v])
            dfs_low[u] = min(dfs_low[u],dfs_low[v]);
    }
    if(dfs_num[u]==dfs_low[u]){
        cout << endl;
        while(true){
            int v = S.back();S.pop_back();
            dfs_visited[v] = false;
            cout << names[v];
            if(u==v) break;
            cout << ", ";
        }
    }
}

int main(){
    int cnt = 0;
    while(cin >> N >> M){
        if(N==0&&M==0) break;
        memset(dfs_visited,0,sizeof(dfs_visited));
        memset(dfs_low, 0, sizeof(dfs_low));
        memset(dfs_num, -1, sizeof(dfs_num));
        memset(adjMat, false, sizeof(adjMat));
        names.clear();
        vals.clear();
        S.clear();
        dfs_counter = 0;
        string a,b;
        for(int i = 0; i < M; i++){
            cin >> a >> b;
            if(vals.find(a)==vals.end()){
                names.push_back(a);
                vals[a] = names.size()-1;
            }
            if(vals.find(b)==vals.end()){
                names.push_back(b);
                vals[b] = names.size()-1;
            }
            adjMat[vals[a]][vals[b]] = true;
        }
        if(cnt>0)cout << endl;
        printf("Calling circles for data set %d:",++cnt);
        for(int i = 0; i < names.size(); i++)
            if(dfs_num[i]==-1)
                dfs(i);
        cout << endl;
    }
    return 0;
}
