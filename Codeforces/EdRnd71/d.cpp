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
#define MA(a,b) ((a+b) % MOD)
#define MS(a,b) ((((a-b+MOD)%MOD)+ MOD)%MOD)
#ifdef JUDGE
#define dbg(x) x
#else
#define dbg(x)
#endif
using namespace std;
typedef long long ll;
typedef complex<double> cc;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
const double EPS = 1e-8;
const int INFI = 1000*1000*1000;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;

const int MX_N = 300023;
const ll MOD = 998244353LL;
ll facs[MX_N];

void getFacs(int lim){
    facs[0] = 1LL;
    for(int i = 1; i <= lim; ++i)
        facs[i] = (((ll)i) * facs[i-1]) % MOD;
}

ll permCount(const vi& ls){ //pre-sorted
    ll n = 1;
    int l = 0;
    while(l < ls.size()){
        ll run = 1;
        while(l+1  < sz(ls) && ls[l+1] == ls[l]){
            ++run;
            ++l;
        }
        n = (n * facs[run]) % MOD;
        ++l;
    }
    return n;
}

ll overlapCount(const vi& firsts, const vi& seconds){
    assert(firsts.size() == seconds.size());

    int l = 0;
    ll n = 1;
    while(l < sz(firsts)){
        int strt = l;
        while(l + 1 < sz(firsts) && firsts[l + 1] == firsts[l])
            l += 1;
        int end = l+1; //exclusve
        vi ls(seconds.begin() + strt, seconds.begin() + end);
        n = (n * permCount(ls)) % MOD;
        l += 1;
    }
    return n;
}

bool isSorted(const vi& ls){
    for(int i = 0; i < sz(ls)-1; ++i)
        if(ls[i] > ls[i+1])
            return false;
    return true;
}


int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int N; rd(N);
    getFacs(N+4);

    vii o(N);
    for(int i = 0; i < N; ++i){
        int a, b; rd2(a,b);
        o[i] = {a,b};
    }
    sort(o.begin(), o.end());

    vi firsts(N), seconds(N);
    for(int i = 0; i < N; ++i){
        firsts[i] = o[i].fi;
        seconds[i] = o[i].se;
    }

    ll d = 0;
    if(isSorted(firsts) && isSorted(seconds))
        d = overlapCount(firsts, seconds);

    sort(firsts.begin(), firsts.end());
    sort(seconds.begin(), seconds.end());
    ll fcnt = permCount(firsts);
    ll scnt = permCount(seconds);

    pr(MS(facs[N], MS(MA(fcnt,scnt), d)));
    return 0;
}
