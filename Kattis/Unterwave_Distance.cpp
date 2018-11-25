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

const int MX_N = 50005;
set<ii> edges;
vi adjList[MX_N];
vector<int> h, a;
ll g[MX_N];

inline ll cube(ll x){return x*x*x; }

ll proc(int x, int y){
    ll mn = abs(cube(g[x]) - cube(g[y]));
    bool xyCon = edges.count({min(x,y), max(x,y)}) > 0;
    bool cN = false;
    bool xU = false;
    bool yU = false;
    for(int v : adjList[x]){
        if(v == y)
            continue;
        bool conY = false;
        for(int u : adjList[v]){
            if(u==y)
                conY=true;
        }
        if(conY)
            cN = true;
        else
            xU = true;
    }
    for(int v : adjList[y]){
        if(v == x)
            continue;
        bool conX = false;
        for(int u : adjList[v]){
            if(u==x)
                conX=true;
        }
        if(conX)
            cN = true;
        else
            yU = true;
    }
    if(xyCon){
        mn = min(mn, abs(cube(g[x]-1) - cube(g[y]+1)));
        mn = min(mn, abs(cube(g[x]+1) - cube(g[y]-1)));
    } else {
        mn = min(mn, abs(cube(g[x]-1) - cube(g[y])));
        mn = min(mn, abs(cube(g[x]) - cube(g[y]-1)));
    }
    if(cN)
        mn = min(mn, abs(cube(g[x]+1) - cube(g[y]+1)));
    if(xU)
        mn = min(mn, abs(cube(g[x]+1) - cube(g[y])));
    if(yU)
        mn = min(mn, abs(cube(g[x]) - cube(g[y]+1)));
    return mn;
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; rd(n);
    char c;
    for(int i =1; i <= n;++i){
        rd2(g[i],c);
        if(c=='h')
            h.pb(i);
        else
            a.pb(i);
    }
    sort(a.begin(), a.end(), [](int i, int j){return g[i] < g[j];});
    sort(h.begin(), h.end(), [](int i, int j){return g[i] < g[j];});
    int e; rd(e);
    int x,y;
    for(int i = 0; i < e; ++i){
        rd2(x,y);
        edges.insert({min(x,y),max(x,y)});
        adjList[x].pb(y);
        adjList[y].pb(x);
    }

    ll mn = abs(cube(g[h[0]]) - cube(g[a[0]]));
    for(int v : h){
        int ind = lower_bound(a.begin(), a.end(), v,
                [](const int& i, const int& j){ return g[i] < g[j];}) - a.begin();
        for(int i = 0; i <= 5; ++i){
            if(0<=ind+i&&ind+i < sz(a))
                mn = min(mn, proc(v, a[ind+i]));
            if(0<=ind-i&&ind-i < sz(a))
                mn = min(mn, proc(v, a[ind-i]));
        }
    }
    pr(mn);
    return 0;
}
