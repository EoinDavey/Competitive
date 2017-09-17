#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
constexpr int MX_N=100001;
vector<int> adjList[MX_N];
vector<ii> eList;
int dfs_num[MX_N],dfs_low[MX_N],scc_id[MX_N];
bool vis[MX_N];
int dfs_counter = 0;
int scc_cnt = 0;
int N,M;
stack<int> scc;

void dfs(int u){
    scc.push(u);
    dfs_num[u] = dfs_low[u] = ++dfs_counter;
    vis[u] = true;
    for(auto v : adjList[u]){
        if(dfs_num[v]==0){
            dfs(v);
            dfs_low[u] = min(dfs_low[u],dfs_low[v]);
        } else if(vis[v]){
            dfs_low[u] = min(dfs_low[u],dfs_num[v]);
        }
    }
    if(dfs_low[u]==dfs_num[u]){
        ++scc_cnt;
        while(1){
            int v = scc.top(); scc.pop();
            vis[v] = false;
            scc_id[v] = scc_cnt;
            if(v==u)
                break;
        }
    }
}

int main(){
    int T; scanf("%d",&T);
    while(T --> 0){
        scanf("%d %d",&N,&M);
        eList.clear();
        for(int i= 0; i < N; ++i)
            adjList[i].clear();
        memset(vis,0,sizeof(vis));
        memset(dfs_num,0,sizeof(dfs_num));
        memset(dfs_low,0,sizeof(dfs_low));
        memset(scc_id,0,sizeof(scc_id));
        dfs_counter=0;
        scc_cnt=0;
        while(!scc.empty())
            scc.pop();
        int a,b;
        for(int i = 0; i < M; ++i){
            scanf("%d %d",&a,&b); --a;--b;
            adjList[a].push_back(b);
            eList.push_back(make_pair(a,b));
        }
        for(int i = 0; i < N; ++i)
            if(dfs_num[i]==0)
                dfs(i);
        int incnt[scc_cnt]; memset(incnt,0,sizeof(incnt));
        for(auto i : eList)
            if(scc_id[i.first] != scc_id[i.second])
                incnt[scc_id[i.second]]++;
        int cnt = 0;
        for(int i = 0; i<scc_cnt; ++i)
            if(incnt[i]==0)
                cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
