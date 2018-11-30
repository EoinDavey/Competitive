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

const int MX_N = 300003;
int N;
int l[MX_N], r[MX_N];
int minl[MX_N], maxl[MX_N];
int minr[MX_N], maxr[MX_N];

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd(N);
    for(int i = 0; i < N; ++i)
        rd2(l[i],r[i]);
    int mx = -INFI;
    int mn = INFI;
    for(int i = 0; i < N; ++i){
        minl[i] = mn;
        maxl[i] = mx;
        mx = max(mx, l[i]);
        mn = min(mn, r[i]);
    }
    mx = -INFI;
    mn = INFI;
    for(int i = N-1; i >=0; --i){
        minr[i] = mn;
        maxr[i] = mx;
        mx = max(mx, l[i]);
        mn = min(mn, r[i]);
    }
    mx = 0;
    for(int i = 0; i < N; ++i)
        mx = max(mx, min(minl[i], minr[i]) - max(maxl[i],maxr[i]));
    pr(mx);
    return 0;
}
