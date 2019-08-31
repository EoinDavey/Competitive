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

const int MX_N = 200002;
int a[MX_N];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int N, K; rd2(N, K);
    for(int i = 0; i < N; ++i)
        rd(a[i]);
    map<int, vi> sts;
    for(int i = 0; i < N; ++i){
        int cst = 0;
        int v = a[i];
        for(;;){
            sts[v].pb(cst);
            v/=2;
            cst += 1;
            if(v==0)
                break;
        }
    }
    int mn = INFI;
    for(auto& i : sts){
        if(sz(i.se) < K)
            continue;
        sort(i.se.begin(), i.se.end());
        int cst = 0;
        for(int j = 0; j < K; ++j)
            cst += i.se[j];
        mn = min(mn, cst);
    }
    pr(mn);
    return 0;
}
