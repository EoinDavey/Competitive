#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define rd3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define rd2(x,y) scanf("%d %d", &x, &y)
#define rd(x) scanf("%d", &x)
#define pr3(x,y,z) printf("%d %d %d\n", x, y, z)
#define pr2(x,y) printf("%d %d\n", x, y)
#define pr(x) printf("%d\n", x)
using namespace std;
typedef long long ll;
typedef complex<double> cc;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INFI = 1000*1000*1000;
const double EPS = 1e-8;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;
const int MX_N = 3 * 100 * 1000 + 2;
const int MX_SZ =  15 * 1000 * 1000 + 3;

int dsieve[MX_SZ];
int pcnt[MX_SZ];
int N,a[MX_N];

int main(){
    for(int i = 2; i < MX_SZ; ++i)
        if(dsieve[i]==0)
            for(int j = i; j < MX_SZ; j+=i)
                dsieve[j] = i;
    rd(N);
    for(int i = 0; i < N; ++i)
        rd(a[i]);
    int ogcd = a[0];
    for(int i = 1; i < N; ++i)
        ogcd = __gcd(a[i], ogcd);
    for(int i = 0; i < N; ++i)
        a[i] /= ogcd;

    for(int i = 0; i < N; ++i){
        int x = a[i];
        while(dsieve[x]){
            int f = dsieve[x];
            pcnt[f]++;
            while(x%f==0)
                x/=f;
        }
    }
    int mx = 0;
    for(int i = 0; i < MX_SZ; ++i)
        mx = max(mx, pcnt[i]);
    if(mx)
        pr(N-mx);
    else
        puts("-1");
    return 0;
}
