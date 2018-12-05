#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define rd3(x,y,z) cin >> x >> y >> z
#define rd2(x,y) cin >> x >> y
#define rd(x) cin >> x
#define pr3(x,y,z) cout << x << ' ' << y << ' ' << z << endl
#define pr2(x,y) cout << x << ' ' << y << endl
#define pr(x) cout << x << endl
#define debug(x) cout << #x << " = "<< x << ' ' << endl
using namespace std;
typedef long long ll;
typedef complex<double> cc;
typedef pair<int, int> ii;
typedef vector<int> vi;
const double EPS = 1e-8;
const int INFI = 1000*1000*1000;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;

struct lk{ int v,l,r; };
const int MX_N = 1001;
const int MX_L = 5001;
int N, L, B, S, D;
vector<ii> ivals;
vector<lk> adjList[MX_N];
vi ts;
bool vis[MX_N];
set<int> reached;

void dfs(int u, int l, int r, int ind){
    vis[u] = true;
    if(u==D){
        reached.insert(ind);
        return;
    }
    for(const auto &c : adjList[u]){
        if(!vis[c.v] && c.l <= l && r <= c.r)
            dfs(c.v, l, r, ind);
    }
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd3(N,L,B);
    rd2(S,D);
    int a,b, x, y;
    for(int i = 0; i < L; ++i){
        cin >> a >> b >> x >> y;
        adjList[a].pb({b,x,y});
        ts.pb(x);
        ts.pb(y);
    }
    ts.pb(1);ts.pb(B);
    sort(ts.begin(), ts.end());
    for(int i = 1; i < sz(ts); ++i)
        ivals.pb({ts[i-1], ts[i]});
    for(int i = 0; i < sz(ivals); ++i){
        memset(vis, 0, sizeof(vis));
        dfs(S, ivals[i].fi, ivals[i].se, i);
    }
    int sm = 0;
    set<int> ends;
    for(int v : reached){
        sm += max(0, ivals[v].se - ivals[v].fi - 1);
        ends.insert(ivals[v].se);
        ends.insert(ivals[v].fi);
    }
    sm += sz(ends);
    pr(sm);
    return 0;
}
