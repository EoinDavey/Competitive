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

const int MX_N = 1010;
int threads[MX_N], memo[MX_N][MX_N];
int A, P, tCount;
int p[MX_N], mn[MX_N], sz[MX_N];
int find(int i){ return p[i] = (i == p[i] ? i : find(p[i]));}
void join(int a, int b){
    a=find(a); b=find(b);
    if(a == b)
        return;
    p[a]=b;
    mn[b] = min(mn[b], mn[a]);
    sz[b] += sz[a];
}

int dp(int thread, int sz){
    if(thread == tCount)
        return abs(A-sz);

    if(memo[thread][sz] != -1)
        return memo[thread][sz];

    // put on this page
    int scr1 = dp(thread + 1, sz + threads[thread]);

    // new page
    int scr2 = max(abs(A - sz), dp(thread + 1, threads[thread]));

    return memo[thread][sz] = min(scr1, scr2);
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(rd2(A, P)){
        memset(memo, -1, sizeof(memo));
        for(int i = 1; i <= P; ++i){
            p[i] = i;
            mn[i] = i;
            sz[i] = 1;
        }
        { int x;
            for(int i = 1; i <= P; ++i){
                rd(x);
                if(x != 0)
                    join(i,x);
            }
        }
        vector<int> keys;
        for(int i = 1; i <= P; ++i)
            if(find(i) == i)
                keys.pb(i);
        tCount = sz(keys);
        sort(keys.begin(), keys.end(), [](int x, int y) bool { return mn[x] < mn[y]; });
        for(int i = 0; i < tCount; ++i)
            threads[i] = sz[keys[i]];
        pr(dp(0, 0));
    }
    return 0;
}
