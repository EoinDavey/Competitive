#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define ma(x,y) (((x+y)%MOD+MOD)%MOD)
#define mm(x,y) (((x*y)%MOD+MOD)%MOD)
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

const int MX_N = 1002;
const ll MOD = 998244353;
int N,M;
ll board[MX_N][MX_N];
ll dp[MX_N][MX_N];

ll fexp(ll a, ll x, ll mod){		// Fast exponenciation returns a^x % mod
	if(x==0LL)return 1ll;
	if(x%2LL==0){
		ll y=fexp(a, x/2, mod);
		return (y*y)%mod;
	}
	return (a*fexp(a, x-1, mod))%mod;
}

ll divv(ll a, ll b, ll mod){	// Division with mod returns a/b % mod
	return (a*fexp(b, mod-2, mod))%mod;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd2(N,M);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            rd(board[i][j]);
    vector<ii> prs;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            prs.pb({i,j});
    sort(prs.begin(), prs.end(), [](const ii& a, const ii& b){
                return board[a.fi][a.se] < board[b.fi][b.se];
            });

    ll sz = 0;
    ll nsz = 0;
    ll xsm,x2sm,ysm,y2sm;
    xsm=x2sm=ysm=y2sm = 0;
    ll nxsm,nx2sm,nysm,ny2sm;
    nxsm=nx2sm=nysm=ny2sm = 0;
    ll prv = -1;

    ll dpsm,ndpsm;
    dpsm = ndpsm = 0;

    ll x,y;
    for(const auto& i : prs){
        x = i.fi,y=i.se;
        if(board[x][y] != prv){
            sz = nsz;
            xsm=nxsm;
            x2sm=nx2sm;
            ysm=nysm;
            y2sm=ny2sm;
            dpsm = ndpsm;
            prv = board[x][y];
        }
        dp[x][y] = ma(dp[x][y], dpsm);
        dp[x][y] = ma(dp[x][y], ma(mm(sz, mm(y,y)), ma(-mm(2LL,mm(y,ysm)), y2sm)));
        dp[x][y] = ma(dp[x][y], ma(mm(sz, mm(x,x)), ma(-mm(2LL,mm(x,xsm)), x2sm)));
        if(sz)
            dp[x][y] = divv(dp[x][y], sz, MOD);
        ndpsm = ma(ndpsm, dp[x][y]);
        nxsm = ma(nxsm, x);
        nx2sm = ma(nx2sm, mm(x,x));
        nysm = ma(nysm, y);
        ny2sm = ma(ny2sm, mm(y,y));
        nsz = ma(nsz,1);
    }
    int r,c;
    rd2(r,c);
    --r,--c;
    pr(dp[r][c]);
    return 0;
}
