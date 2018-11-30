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

const int MX_N = 500005;

vi occ[MX_N];
int a[MX_N];
int c[MX_N];
int N, C;

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd2(N,C);
    for(int i = 0; i < N; ++i)
        rd(a[i]);
    for(int i = 0; i < N; ++i)
        occ[a[i]].pb(i);
    for(int i = 0; i < N; ++i){
        c[i] = (a[i]==C);
        if(i > 0)
            c[i] += c[i-1];
    }
    int mx = c[N-1];
    for(int i = 1; i < MX_N; ++i){
        if(i==C)
            continue;
        if(!sz(occ[i]))
            continue;
        int v = i;
        sort(occ[v].begin(), occ[v].end());
        int mxV = -INFI;
        int mnL = INFI;
        for(int j = 0; j < sz(occ[v]); ++j){
            int val = j+1 - c[occ[v][j]];
            mnL = min(mnL, val-1);
            mxV = max(mxV, val-mnL);
        }
        mx = max(mx, c[N-1] + mxV);
    }
    pr(mx);
    return 0;
}
