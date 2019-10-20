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
#define m(a,b) ((a+b)%MOD)
#define mm(a,b) ((a*b)%MOD)
using namespace std;
typedef long long ll;
typedef complex<double> cc;
typedef pair<int, int> ii;
typedef vector<int> vi;
const double EPS = 1e-8;
const int INFI = 1000*1000*1000;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;

const int MX_N = 100010;
const ll MOD = 1000000007LL;
int p[MX_N];
ll sz[MX_N];
int N;

struct edge{
    int a,b; ll w;
    bool operator<(const edge& e) const {
        if(w != e.w)
            return w < e.w;
        if(a != e.a)
            return a < e.a;
        return b < e.b;
    }
};

int find(int i){ return p[i] = (p[i] == i ? i : find(p[i]));}
ll join(int a, int b){
    a = find(a); b = find(b);
    if(a == b)
        return 0;
    ll ans = mm(sz[a], sz[b]);
    p[a] = b;
    sz[b] += sz[a];
    return ans;
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd(N);
    for(int i = 1; i <= N; ++i){
        p[i] = i;sz[i] = 1;
    }
    vector<edge> elist;
    for(int i = 0; i < N-1; ++i){
        int a,b;
        ll w;
        rd3(a,b,w);
        elist.pb({a,b,w});
    }
    sort(elist.begin(),elist.end());
    ll sm = 0;
    for(const auto &e : elist){
        sm = m(e.w * join(e.a, e.b),sm);
    }
    pr(sm);
    return 0;
}
