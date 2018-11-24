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

const int MX_N = 100001;
const int MX_A = 1000001;
const ll MOD = 1000*1000*1000 + 7;
ll L[2][MX_A], dp[MX_N];
ll a[MX_N];
int N;

#define ma(x,y) (((x+y)%MOD + MOD)%MOD)

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd(N);
    for(int  i = 0; i< N; ++i)
        rd(a[i]);

    L[0][0] = 1;
    for(int i = 0; i < N; ++i){
        int v = a[i];
        int lm = sqrt(v)+3;
        for(int j = 1; j <= lm; ++j){
            if(v%j==0){
                L[1][j]= ma(L[0][j], L[0][j-1]);
                if(v/j != j)
                    L[1][v/j]=ma(L[0][v/j], L[0][v/j-1]);
            }
        }
        for(int j = 1; j <= lm; ++j){
            if(v%j==0){
                L[0][j]= L[1][j];
                if(v/j != j)
                    L[0][v/j]=L[1][v/j];
            }
        }
    }
    ll sm = 0;
    for(int i = 1; i < MX_A; ++i)
        sm = ma(sm, L[0][i]);
    pr(sm);
    return 0;
}
