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

const int MX_N = 1000010;
vi adjList[MX_N];
int ord[MX_N];
int order = 1;
ii rngs[MX_N];

int tree[MX_N];

int lsOne(int i){ return i&(-i); }

void update(int k, int v){
    for(; k<MX_N; k+=lsOne(k))
        tree[k]+=v;
}

int query(int k){
    int cnt=0;
    for(; k; k-=lsOne(k)){
        cnt+=tree[k];
    }
    return cnt;
}

int mapRngs(int u){
    int ind = ord[u] = order++;
    int mx = ind;
    for(int v : adjList[u])
        mx = max(mx, mapRngs(v));
    rngs[u] = {ind, mx};
    return mx;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int N; rd(N);
    for(int i = 1; i <= N-1; ++i){
        int p; rd(p);
        adjList[p].pb(i);
    }
    mapRngs(0);
    int Q; rd(Q);
    while(Q --> 0){
        int q; rd(q);
        if(q == 1){
            int u, v; rd2(u, v);
            update(ord[u], v);
        } else {
            int u, l, r; rd(u);
            l = rngs[u].fi;
            r = rngs[u].se;
            pr(query(r) - query(l-1));
        }
    }
    return 0;
}
