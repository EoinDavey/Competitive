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

const int MX_N = 1001;
int p[MX_N];
double r[MX_N], x[MX_N], y[MX_N];
int find(int i){ return p[i] = i == p[i] ? i : find(p[i]); }
int join(int a, int b){ p[find(a)] = find(b);}
int N;

double distsq(int a, int b){
    return pow(x[a]-x[b], 2) + pow(y[a]-y[b], 2);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    double R;
    rd2(N, R);
    for(int i = 1; i <= N; ++i)
        rd3(x[i], y[i], r[i]);
    x[0] = -R, y[0] = 0, r[0] = 0;
    x[N + 1] = R, y[N + 1] = 0, r[N + 1] = 0;
    N += 2;
    for(int i = 0; i < N; ++i)
        p[i] = i;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < i; ++j)
            if(distsq(i, j) <= pow(r[i] + r[j], 2))
                join(i, j);
    int compcnt = 0;
    for(int i = 0; i < N; ++i)
        if(p[i] == i)
            ++compcnt;
    pr(compcnt - 1);
    return 0;
}
