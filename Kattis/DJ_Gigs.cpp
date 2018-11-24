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
struct gig{
    ll v,s,e,m, ind;
    bool operator<(const gig& g) const {
        if(s != g.s)
            return s < g.s;
        if(e != g.e)
            return e < g.e;
        if(v != g.v)
            return v < g.v;
        return m < g.m;
    }
};

const int MX_G = 200002;
const int MX_K = 102;
ll G, K, R;
ll dist[MX_K][MX_K];
gig gigs[MX_G];
vi giglist[MX_K];
ll dp[MX_G];

int main(){
    rd3(G,K,R);
    for(int i = 0; i < K; ++i)
        for(int j = 0; j < K; ++j)
            if(i!=j)
                dist[i][j]=INFL;
    ll a,b,t;
    for(int i = 0; i < R; ++i){
        rd3(a,b,t);
        --a,--b;
        dist[a][b] = dist[b][a] = t;
    }
    for(int k = 0; k < K; ++k)
        for(int i = 0; i < K; ++i)
            for(int j = 0; j < K; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    gigs[0] = {0,0,0,0};
    for(int i = 1; i <= G; ++i){
        cin >>gigs[i].v >>gigs[i].s >>gigs[i].e >>gigs[i].m;
        --gigs[i].v;
    }
    sort(gigs, gigs+G+1);
    for(int i = 0; i <= G; ++i)
        giglist[gigs[i].v].pb(i);
    for(int i = 0; i < K; ++i)
        for(int j = 0; j < sz(giglist[i]); ++j)
            gigs[giglist[i][j]].ind = j;

    vi::iterator k;
    for(int g = G; g>=0; --g){
        dp[g] = gigs[g].m;
        int v = gigs[g].v;

        // take gig g
        for(int i = 0; i < K; ++i){
            ll tA = gigs[g].e + dist[v][i];
            k = lower_bound(giglist[i].begin(), giglist[i].end(),
                    tA, [&](const ll& a, const ll& b){ return gigs[a].s < b; });
            if(k == giglist[i].end())
                continue;
            if(*k != g)
                dp[g] = max(dp[g], gigs[g].m + dp[*k]);
        }
        // don't take gig g
        int ind = gigs[g].ind+1;
        if(ind < sz(giglist[v]))
            dp[g] = max(dp[g], dp[giglist[v][ind]]);
    }
    pr(dp[0]);
    return 0;
}
