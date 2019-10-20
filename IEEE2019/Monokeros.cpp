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
const int INFI = 2*1000*1000*1000;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;

map<ll,ll> depths;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll N; rd(N);
    depths[INFL] = 1;
    for(int i = 0; i < N; ++i){
        ll x; rd(x);
        const auto &ivl = depths.lower_bound(x);
        cout << ivl->second << ' ';
        if(x != ivl->first)
            depths[x] = ivl->second + 1;
        depths[ivl->first] = ivl->second+1;
    }
    cout << endl;
    return 0;
}
