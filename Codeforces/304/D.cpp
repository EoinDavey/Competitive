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

const int MX_N = 5000001;
int ex_sieve[MX_N];
int n_facs[MX_N];
int sm[MX_N];

int main(){
    for(int i = 2; i < MX_N; ++i) {
        if(ex_sieve[i] != 0)
            continue;
        for(int j = i; j < MX_N; j += i)
            ex_sieve[j] = i;
    }
    n_facs[1] = 0;
    for(int i = 2; i < MX_N; ++i) {
        int x = i;
        while(x != 1) {
            x /= ex_sieve[x];
            ++n_facs[i];
        }
    }
    for(int i = 2; i < MX_N; ++i)
        sm[i] = n_facs[i] + sm[i-1];
    int T, a, b;
    scanf("%d", &T);
    while(T --> 0 ) {
        scanf("%d %d", &a, &b);
        printf("%d\n", sm[a] - sm[b]);
    }
    return 0;
}
