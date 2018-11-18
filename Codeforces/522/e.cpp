#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define rd3(x,y,z) cin >> x >> y >> z;
#define rd2(x,y) cin >> x >> y;
#define rd(x) cin >> x;
#define pr3(x,y,z) cout << x << ' ' << y << ' ' << z << endl;
#define pr2(x,y) cout << x << ' ' << y << endl;
#define pr(x) cout << x << endl;
#define debug(x) cout << #x << " = "<< x << ' ' << endl;
using namespace std;
typedef long long ll;
typedef complex<double> cc;
typedef pair<int, int> ii;
typedef vector<int> vi;
const double EPS = 1e-8;
const int INFI = 1000*1000*1000;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;

const int MX_N = 102;
int memo[MX_N][1001][MX_N];
int a[MX_N];
int N;

int dp(int sz, int mass, int p){
    //printf("dp(%d,%d,%d)\n", sz, mass, p);
    
    if(sz==0)
        return mass==0;
    if(p==0){
        if(sz==1)
            return a[p] == mass ? 1 : 0;
        else if(sz==0)
            return mass==0 ? 1 : 0;
        return 0;
    }
    if(mass < 0)
        return 0;
    if(memo[sz][mass][p] != -1)
        return memo[sz][mass][p];
    return memo[sz][mass][p] = dp(sz,mass,p-1) + dp(sz-1, mass - a[p], p-1);
}

int main(){
    //ios::sync_with_stdio(false);
    memset(memo, -1, sizeof(memo));
    rd(N);
    int sm = 0;
    for(int i = 0; i < N; ++i){
        rd(a[i]);
        sm+=a[i];
    }
    int mx = 0;
    for(int k = 1; k <= N; ++k){
        for(int m = 0; m <= sm; ++m){
            if(dp(k,m,N-1) == 1)
                mx = max(mx, k);
        }
    }
    pr(mx);
    return 0;
}
