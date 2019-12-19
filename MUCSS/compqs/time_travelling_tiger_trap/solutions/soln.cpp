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

const int MX_N = 200020;
int N;
vi tgrs;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd(N); assert(N <= 200000);
    tgrs.resize(N);
    for(int i = 0; i < N; ++i){
        int x; rd(x); assert(0 <= x && x <= INFI);
        tgrs[i] = x;
    }
    sort(tgrs.begin(), tgrs.end());
    int Q; rd(Q); assert(0 < Q && Q <= 200000);
    while(Q --> 0){
        int L, R; rd2(L, R);
        assert(0 <= L && L <= INFI && 0 <= R && R <= INFI && L <= R);
        auto lb = lower_bound(tgrs.begin(), tgrs.end(), L);
        auto rb = upper_bound(tgrs.begin(), tgrs.end(), R);
        if(lb == tgrs.end() || rb == tgrs.begin()){
            pr(0);
            continue;
        }
        --rb;
        pr(distance(lb, rb) + 1);
    }
    return 0;
}
