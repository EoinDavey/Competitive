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

ll memo[MX_N][2];

ll dp(const string& s, const ll a, const ll b,
        int ind, bool hi) {

    if(memo[ind][hi] != -1)
        return memo[ind][hi];

    if(ind == s.size()){
        if(hi)
            return memo[ind][hi] = INFI;
        return memo[ind][hi] = 0;
    }

    bool phi = s[ind] == '1' || (ind+1 < s.size() && s[ind+1] == '1');

    if(hi){
        if(phi)
            return memo[ind][hi] = 2*b + a + dp(s,a,b, ind+1, true);
        else
            return memo[ind][hi] = min(2*b + a + dp(s,a,b,ind+1,true),
                    b + 2*a + dp(s,a,b,ind+1,false));
    }

    if(phi)
        return memo[ind][hi] = 2*b + 2*a + dp(s,a,b, ind+1, true);

    return memo[ind][hi] = min(2*b + 2*a + dp(s,a,b,ind+1,true),
            b + a + dp(s,a,b,ind+1,false));
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T_;rd(T_);
    while(T_-->0){
        ll n,a,b;rd3(n,a,b);
        string s; rd(s);
        memset(memo, -1, sizeof(memo));
        pr(b + dp(s,a,b,0,false));
        dbg(for(int j = 1; j >= 0; --j){
            for(int i = 0; i <= n; ++i){
                if(memo[i][j] >= INFI)
                    printf("IIII ");
                else
                    printf("%4d ", memo[i][j]);
            }
            putchar('\n');
        })
    }
    return 0;
}
