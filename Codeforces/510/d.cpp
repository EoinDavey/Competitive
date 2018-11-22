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

const int MX_N = 500010;
ll a[MX_N];
ll sm[MX_N];
unordered_map<ll, int> indMp;
int perm[MX_N];
ll tree[MX_N];

inline int LSOne(int i) {return i &(-i);}
void update(int k, ll v){
    for(;k<MX_N; k+=LSOne(k))
        tree[k]+=v;
}
ll query(int k){
    ll o = 0;
    for(;k;k-=LSOne(k))
        o+=tree[k];
    return o;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int N; rd(N);
    ll T; rd(T);
    for(int i = 0; i < N; ++i)
        rd(a[i]);
    for(int i= 0; i < N; ++i)
        sm[i] = a[i] + (i > 0 ? sm[i-1] : 0);
    vector<ll> ns;
    ns.pb(0);
    for(int i = 0; i < N; ++i){
        ns.pb(sm[i]);
        ns.pb(sm[i]-T+1);
    }
    for(int i = 0; i < sz(ns); ++i)
        perm[i]=i;
    sort(perm, perm+sz(ns), [&](int a, int b){ return ns[a] < ns[b]; });
    for(int i = 0; i < sz(ns); ++i)
        indMp[ns[perm[i]]] = MX_N - i - 2;
    ll ans = 0;
    update(indMp[0], 1);
    for(int i = 0; i < N; ++i){
        ll v = query(indMp[sm[i]-T+1]);
        ans+=v;
        update(indMp[sm[i]], 1);
    }
    pr(ans);
    return 0;
}
