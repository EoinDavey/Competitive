#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int MX_N = 10002;
vector<int> adjList[MX_N];
int N;
ll sz[MX_N];
ll mx = 0;
ll ans = 0;
ll totpairs;

void fill_sz(int u, int p){
    sz[u] = 1;
    for(int v : adjList[u]){
        if(v!=p){
            fill_sz(v,u);
            sz[u]+=sz[v];
        }
    }
}

void solve(int u, int p){
    vector<ll> chd;
    ll dmg = totpairs;
    for(int v : adjList[u]){
        if(v==p)
            continue;
        solve(v,u);
        ll n = (sz[v]*(sz[v]-1))/2;
        dmg -= n;
        chd.pb(sz[v]);
    }
    if(sz[u] < N){
        ll n = N-sz[u];
        chd.pb(n);
        dmg -= ((n*(n-1))/2);
    }
    if(dmg > mx){
        mx = dmg;
        sort(chd.begin(),chd.end(),greater<ll>());
        if(chd.size()>1){
            ll mx1 = chd[0];
            ll mx2 = chd[1];
            dmg -= (mx1*mx2);
        }
        ans = dmg;
    }
}

int main(){
    cin >> N;
    totpairs = (N*(N-1))/2;
    ++N;
    int u,v;
    for(int i = 0; i < N-1; ++i){
        scanf("%d %d",&u,&v);
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    fill_sz(0, -1);
    solve(0, -1);
    cout << mx << ' ' << ans << endl;
    return 0;
}
