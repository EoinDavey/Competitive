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

const int MX_N = 200023;
int N, K;
int p[MX_N],q[MX_N];
int mx[MX_N],mn[MX_N];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd2(N, K);
    for(int i = 0; i < N; ++i)
        rd(p[i]);
    for(int i = 0; i < N; ++i)
        rd(q[i]);
    for(int i = 0; i < N; ++i)
        mn[p[i]] = mx[p[i]] = i;
    for(int i = 0; i < N; ++i)
        mx[q[i]] = max(mx[q[i]], i);
    for(int i = 0; i < N; ++i)
        mn[q[i]] = min(mn[q[i]], i);
    vii ivals, intvls;
    for(int i = 1; i <= N; ++i)
        ivals.pb({mn[i], mx[i]});
    sort(ivals.begin(), ivals.end());
    int l = ivals[0].fi; int e = ivals[0].se;
    for(const auto& i : ivals) {
        if(i.fi > e){
            intvls.pb({l,e});
            l = i.fi, e=i.se;
        }
        e = max(e, i.se);
    }
    intvls.pb({l,e});
    char c = 'a';
    int cnt = 1;
    sort(intvls.begin(), intvls.end());
    string o(N, '1');
    for(const auto& i : intvls){
        for(int j = i.fi; j <= i.se; ++j)
            o[j] = c;
        if(i.fi >= 1 && o[i.fi-1] != o[i.fi])
            ++cnt;
        if(c < 'z')
            ++c;
    }
    for(int i = 0; i < N; ++i)
        assert(o[i] != '1');
    string out = o;
    for(int i = 0; i < N; ++i)
        out[p[i]-1] = o[i];
    if(cnt < K)
        pr("NO");
    else{
        pr("YES");
        pr(out);
    }
    return 0;
}
