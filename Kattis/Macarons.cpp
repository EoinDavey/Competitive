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
#define ma(x,y) (((x+y)%MOD + MOD)%MOD)
#define mm(x,y) ((x*y)%MOD)
using namespace std;
typedef long long ll;
typedef complex<double> cc;
typedef pair<int, int> ii;
typedef vector<int> vi;
const double EPS = 1e-8;
const int INFI = 1000*1000*1000;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;

const int MX_N = 1<<9;
const ll MOD = 1000*1000*1000;
ll T[MX_N][MX_N], ans[MX_N][MX_N], tmp[MX_N][MX_N];
ll N, M;
ll fib[] = {1,1,2,3,5,8,13,21,34,55,89};

ll ways(int st1, int st2){
    if((st1&st2)!=0)
        return 0;
    ll w = 1;
    int rn = 0;
    for(int i = 0; i < N; ++i){
        if((st1&(1<<i))==0 && (st2&(1<<i))==0){
            rn+=1;
        } else {
            w *= fib[rn];
            rn = 0;
        }
    }
    w *= fib[rn];
    return w;
}

void matmul(ll a[MX_N][MX_N], ll b[MX_N][MX_N], ll c[MX_N][MX_N], ll md){
    for(int i = 0; i < (1<<N); ++i){
        for(int j = 0;j < (1<<N); ++j){
            c[i][j]=0;
            for(int h = 0; h < (1<<N); ++h)
                c[i][j] = ma(c[i][j], mm(a[i][h], b[h][j]));
        }
    }
}

void matexp(ll a[MX_N][MX_N], ll ans[MX_N][MX_N], ll b){
    for(int i = 0; i < (1<<N); ++i)
        for(int j = 0; j < (1<<N); ++j)
            ans[i][j] = i==j;
    while(b){
        if(b&1){
            matmul(ans, a, tmp,MOD);
            for(int i = 0; i < (1<<N); ++i)
                for(int j = 0; j < (1<<N); ++j)
                    ans[i][j] = tmp[i][j];
            --b;
        } else {
            matmul(a, a, tmp, MOD);
            for(int i = 0; i < (1<<N); ++i)
                for(int j = 0; j < (1<<N); ++j)
                    a[i][j] = tmp[i][j];
            b >>= 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd2(N,M);
    for(int i = 0; i < (1<<N); ++i)
        for(int j = 0; j < (1<<N); ++j)
            T[i][j] = ways(i, j);
    matexp(T, ans, M);
    pr(ans[0][0]);
    return 0;
}
