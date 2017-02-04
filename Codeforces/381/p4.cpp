#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int N;

int a[200002];
int p[200002];
int w[200002];
int c[200002];
long long depth[200002];
int output[200002];
vector<int> adjList[200002];

int findULim(vector<int> * path, int u){
    int pos = lower_bound(path->begin(), path->end(), true, [=](int v, bool val){ return (depth[u] - depth[v] <= a[u]) < val;}) - path->begin();
    if(pos != path->size()){
        c[u]++;
        c[(*path)[pos]]--;
    }
}

void dfs(vector<int> * path,int pos, long long d){
    depth[pos] = d;
    findULim(path,pos);
    path->push_back(pos);
    for(int i = 0; i < adjList[pos].size(); i++){
        dfs(path, adjList[pos][i], d+((long long)w[adjList[pos][i]]));
    }
    path->erase(path->end()-1);
}

void propagate(int pos){
    for(int i = 0; i < adjList[pos].size(); i++){
        propagate(adjList[pos][i]);
        output[pos] += output[adjList[pos][i]];
    }
    output[pos]+=c[pos];
}


int main(){
    cin >> N;
    for(int i = 1; i <= N; i++)scanf("%d",&a[i]);
    for(int i = 1; i <= N-1; i++) scanf("%d %d",&p[i+1],&w[i+1]);
    for(int i = 1; i <= N; i++) adjList[p[i+1]].push_back(i+1);
    vector<int> * p = new vector<int>();
    dfs(p,1,0);
    delete p;
    propagate(1);
    for(int i = 1; i <= N; i++)printf("%d ",output[i] - c[i]);
    cout << endl;
    return 0;
}
