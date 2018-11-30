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


const int MX_N = 100002;
int N, M;
vi sub[MX_N];
vi bst[MX_N];
int sums[MX_N];

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd2(N,M);
    int s,r;
    for(int i = 0; i < N; ++i){
        rd2(s,r);
        --s;
        sub[s].pb(r);
    }
    for(int i = 0; i < M; ++i)
        sort(sub[i].begin(), sub[i].end(), greater<int>());
    for(int i = 0; i < M; ++i){
        bst[i].resize(sz(sub[i]));
        for(int j = 0; j < sz(sub[i]); ++j){
            bst[i][j] = sub[i][j] + (j > 0 ? bst[i][j-1] : 0);
        }
    }
    for(int i = 0; i < M; ++i)
        for(int j = 0; j < sz(sub[i]); ++j)
            if(bst[i][j] > 0)
                sums[j]+=bst[i][j];
    int mx = 0;
    for(int i = 0; i < N; ++i)
        mx = max(mx, sums[i]);
    pr(mx);
    return 0;
}
