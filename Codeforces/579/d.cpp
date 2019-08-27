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

#define end(x) (sz(x)-1)
const int MX_N = 200002;
string s,t;
int ln[MX_N];
int rn[MX_N];

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd2(s,t);
    ln[0] = s[0] == t[0] ? 1 : 0;
    for(int i = 1; i < sz(s); ++i){
        int pv = ln[i-1];
        ln[i] = pv;
        if(pv < sz(t) && s[i] == t[pv])
            ln[i] = pv + 1;
    }
    for(int i = end(s); i >= 0; --i)
        ln[i] = i-1 >= 0 ? ln[i-1] : 0;

    rn[end(s)] = s[end(s)] == t[end(t)] ? 1 : 0;
    for(int i = end(s)-1; i >= 0; --i){
        int pv = rn[i+1];
        rn[i] = pv;
        if(pv < sz(t) && s[i] == t[end(t)-pv])
            rn[i] = pv + 1;
    }
    for(int i = 0; i <= end(s); ++i)
        rn[i] = i+1 <= end(s) ? rn[i+1] : 0;
    dbg(
        for(int i= 0; i < sz(s); ++i)
            printf("%d ", ln[i]);
        putchar('\n');
        for(int i= 0; i < sz(s); ++i)
            printf("%d ", rn[i]);
        putchar('\n');
    );
    int mx = 0;
    for(int i = 0; i < sz(s); ++i){
        // i is R
        int rl = rn[i];
        int L,R;
        L = 0, R = i;
        while(L < R){
            int md = (L+R)/2;
            int ll = ln[md];
            if(ll + rl >= sz(t))
                R = md;
            else
                L = md+1;
        }
        if(rn[i] + ln[L] >= sz(t))
            mx = max(mx, (i - L + 1));
    }
    pr(mx);
    return 0;
}
