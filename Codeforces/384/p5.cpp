#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>

typedef long long ll;

using namespace std;

int N;
const int mx_n = 222222;
vector<int> adjList[mx_n];
ll a[mx_n];
ll s[mx_n];
ll mx[mx_n];
bool vis[mx_n];
bool leaf[mx_n];
ll INF = 0L;
bool possible = false;
ll ans = -INF;

ll sum(int u){
    vis[u] = true;
    bool mSet = false;
    s[u] = a[u];
    for(int i = 0; i < adjList[u].size(); i++){
        int v = adjList[u][i];
        if(!vis[v]){
            s[u]+=sum(v);
            if(s[v]>mx[u] || !mSet)mx[u] = s[v],mSet=true;
            if(!leaf[v] && mx[v]>mx[u])mx[u] = mx[v];
        }
    }
    if(adjList[u].size()<=1)
        leaf[u]=true;
    return s[u];
}

void dfs(int u){
    vis[u] = true;
    ll mx1,mx2;
    int mSet = 0;
    mx1=mx2=-INF;
    for(int i = 0; i < adjList[u].size(); i++){
        int v = adjList[u][i];
        if(vis[v]) continue;
        dfs(v);
        ll t = s[v];
        if(!leaf[v])
            t = max(t,mx[v]);
        if(t > mx1 || mSet < 1){
            mx2 = mx1;
            mx1 = t;
            mSet++;
        } else if(t > mx2 || mSet < 2){
            mx2 = t;
            mSet++;
        }
    }
    if(adjList[u].size()>= ((u==0)?2:3)){
        if(mx1+mx2 > ans || !possible){
            ans = mx1 + mx2;
        }
        possible = true;
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        scanf("%lld",&a[i]);
    ll iu, iv;
    for(int i = 0; i < N-1; i++){
        scanf("%lld %lld",&iu,&iv);
        adjList[iu-1].push_back(iv-1);
        adjList[iv-1].push_back(iu-1);
    }
    sum(0);
    memset(vis,false,sizeof(vis));
    dfs(0);
    if(possible)
        cout << ans << endl;
    else cout << "Impossible\n";
    return 0;
}
