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

const int MX_N = 100010;
int w[MX_N];

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int N, C; rd2(N, C);
    for(int i = 0; i < N; ++i)
        rd(w[i]);
    sort(w, w+N);
    reverse(w, w+N);
    multiset<int> s(w, w+N);
    vi out;
    int tot = 0;
    for(int i = 0; i < N; ++i){
        int x = w[i];
        if(s.count(x) == 0)
            continue;
        s.erase(s.find(x));
        out.pb(x);
        int tgt = C - x;
        auto it = s.upper_bound(tgt);
        if(it != s.begin()){
            it--;
            int y = *it;
            if(x + y <= C){
                s.erase(it);
                out.pb(y);
            }
        }
        ++tot;
    }
    pr(tot);
    //pr2(N, out.size());
    return 0;
}
