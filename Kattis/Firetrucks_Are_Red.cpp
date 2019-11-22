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
const double EPS = 1e-8;
const int INFI = 1000*1000*1000;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;

const int MX_N = 300000;
int p[MX_N];

int find(int i) { return p[i] = (i == p[i] ? i : find(p[i]));}
void join(int a, int b){ p[find(a)] = find(b); }

struct ans {
    int p, q, r;
};

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int N; rd(N);
    for(int i = 0; i < N; ++i)
        p[i] = i;

    map<int, vi> ns;
    for(int i = 0; i < N; ++i){
        int m; rd(m);
        for(int j = 0; j < m; ++j){
            int d; rd(d);
            if(ns.count(d) == 0)
                ns[d] = vi();
            ns[d].pb(i);
        }
    }

    vector<ans> out;

    for(const auto& x : ns){
        for(int i = 1; i < sz(x.se); ++i){
            if(find(x.se[i]) == find(x.se[i-1]))
                continue;
            join(x.se[i], x.se[i-1]);
            out.pb({x.se[i]+1, x.se[i-1]+1, x.fi});
        }
    }
    if(sz(out) != N-1)
        pr("impossible");
    else{
        for(const auto& x : out){
            pr3(x.p, x.q, x.r);
        }
    }

    return 0;
}
