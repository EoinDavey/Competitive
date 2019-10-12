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

const int MX_N = 200010;
string s;
int N, K;
int oc[3][MX_N];
int ops[3][MX_N];
#define cmap(x) ((x=='R' ? 0 : (x=='G' ? 1 : 2)))

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int Q; rd(Q);
    while(Q-->0){
        rd2(N,K);
        rd(s);
        for(int o = 0; o < 3; ++o){
            int c = o;
            for(int i = 0; i < N; ++i,c=(c+1)%3)
                oc[o][i] = cmap(s[i]) != c;
            dbg(
            printf("o: %d\n", o);
            pr(s);
            c = o;
            for(int i = 0; i < N; ++i,c=(c+1)%3)
                printf("%c",(c==0 ? 'R' : (c==1 ? 'G' : 'B')));
            putchar('\n');
            for(int i = 0; i < N; ++i)
                printf("%d",oc[o][i]);
            putchar('\n');
            );
            ops[o][0] = oc[o][0];
            for(int i = 1; i < N; ++i)
                ops[o][i] = oc[o][i] + ops[o][i-1];
        }
        int mn = N;
        for(int i = 0; i <= N-K; ++i){
            for(int o = 0; o < 3; ++o){
                int cst = ops[o][i + K - 1] - (i > 0 ? ops[o][i-1] : 0);
                mn = min(mn, cst);
            }
        }
        pr(mn);
    }
    return 0;
}
