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

const int MX_N = 200002;
ll h[MX_N];
ll t[MX_N], N, K;

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd2(N, K);
    for(int i = 0; i < N; ++i)
        rd(t[i]);
    sort(t, t+N, greater<ll>());
    for(int i = 1; i < MX_N; ++i)
        h[i] = upper_bound(t,t+N,i,greater<ll>()) - t;
    ll sm = 0;
    ll cnt = 0;

    for(int i = MX_N-1; i >= 1; --i) {
        if(h[i]==N)
            break;
        if(sm + h[i] > K){
            ++cnt;
            sm = h[i];
        } else {
            sm += h[i];
        }
    }

    pr(cnt+(sm > 0 ? 1 : 0));
    return 0;
}
