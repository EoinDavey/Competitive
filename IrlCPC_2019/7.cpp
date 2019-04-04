#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef complex<double> cc;

const int MX_N = 20002;
int dfs_low[MX_N],dfs_num[MX_N];
int sccMp[MX_N];
int dfsCount, sccIdx;
bool vis[MX_N];
stack<int> sccSt;
vi adjList[MX_N];
vector<int> sccs[MX_N];

void tarjans(int u){
    dfs_num[u] = dfs_low[u] = dfsCount++;
    vis[u] = true;
    sccSt.push(u);
    for(int v : adjList[u]){
        if(dfs_num[v]==0){
            tarjans(v);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }else if (vis[v]){
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
    if(dfs_low[u] == dfs_num[u]){
        while(1){
            int v = sccSt.top(); sccSt.pop();
            sccMp[v] = sccIdx;
            sccs[sccIdx].pb(v);
            vis[v] = false;
            if(v==u)
            break;
        }
        sccIdx++;
    }
}

int main(){
    int N; cin >> N;
    string s;
    getline(cin, s);
    for(int i = 0; i < N; ++i){
	getline(cin, s);
	stringstream ss(s);
	int u; ss >> u;
	int v;
	while(ss >> v){
	    adjList[u].pb(v);
	}
    }
    for(int i = 0; i < N; ++i){
	if(dfs_num[i]==0)
	    tarjans(i);
    }
    for(int i = 0; i < N; ++i){
        sort(sccs[i].begin(), sccs[i].end());
    }
    sort(sccs, sccs+sccIdx, [&](const vi& a, const vi& b){
		return a[0] < b[0];
	    });
    for(int i = 0; i < sccIdx; ++i){
	if(sccs[i].empty())
	    continue;
	for(int v : sccs[i])
	    cout << v << ' ';
	cout << endl;
    }
    return 0;
}
