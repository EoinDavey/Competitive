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
#ifdef JUDGE
#define dbg(x) x
#else
#define dbg(x)
#endif
using namespace std;
typedef long long ll;
typedef complex<double> cc;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const double EPS = 1e-8;
const int INFI = 1000*1000*1000;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;


const int MX_N = 200002;

struct edge{
    int u,v,w;
    bool operator<(const edge& rhs) const {
        if(w != rhs.w)
            return w < rhs.w;
        if(u != rhs.u)
            return u < rhs.u;
        return v < rhs.v;
    }
};
vector<edge> edgeList;
int N, M;

int p[MX_N], sz[MX_N];
int find(int i){ return p[i] = (p[i] == i ? i : find(p[i]));}
void join(int a, int b){
    a = find(a), b = find(b);
    if(a == b)
        return;
    p[a] = b;
    sz[b] += sz[a];
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd2(N,M);
    for(int i = 0; i < N; ++i)
        p[i] = i, sz[i] = 1;
    {
        int u,v,w;
        for(int i = 0; i < N-1; ++i){
            rd3(u,v,w);--u,--v;
            edgeList.pb({u,v,w});
        }
    }
    sort(edgeList.begin(),edgeList.end());
    map<int, ll> wghts;
    for(const auto& e : edgeList){
        ll szu = sz[find(e.u)];
        ll szv = sz[find(e.v)];
        wghts[e.w] += szu*szv;
        join(e.u, e.v);
    }
    vector<pair<int, ll> > wghtls;
    for(const auto& i : wghts)
        wghtls.pb({i.fi, i.se});
    sort(wghtls.begin(), wghtls.end());
    vi qs;
    {
        int q;
        for(int i = 0; i < M; ++i){
            rd(q);
            qs.pb(q);
        }
    }
    vi sqs = qs;
    sort(sqs.begin(), sqs.end());
    map<int, ll> ans;
    ll sm = 0;
    int i = 0;
    for(auto q : sqs){
        while(i < sz(wghtls) && wghtls[i].fi <= q){
            sm += wghtls[i].se;
            ++i;
        }
        ans[q] = sm;
    }
    for(auto q : qs){
        cout << ans[q] << " ";
    }
    cout << endl;
    return 0;
}
