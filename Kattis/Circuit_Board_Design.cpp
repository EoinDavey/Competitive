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
#define X(x) real(x)
#define Y(x) imag(x)
using namespace std;
typedef long long ll;
typedef complex<double> cc;
typedef pair<int, int> ii;
typedef vector<int> vi;
const double EPS = 1e-8;
const int INFI = 1000*1000*1000;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;

const int MX_N = 1001;
vi adjList[MX_N];
int sz[MX_N];
int N;
cc po[MX_N];

void fill_sz(int u, int p){
    sz[u] = 1;
    for(int v : adjList[u]){
        if(v==p)
            continue;
        fill_sz(v,u);
        sz[u]+=sz[v];
    }
}

int get_centroid(int u, int n, int p){
    for(int v : adjList[u]){
        if(v==p)
            continue;
        if(sz[v] > n/2)
            return get_centroid(v, n, u);
    }
    return u;
}

void build(int ind, int p, double l, double r, cc pos) {
    po[ind] = pos;
    double pv = l;
    double ln = r-l;
    double nkids = sz[ind]-1.0;
    for(int v : adjList[ind]){
        if(v == p)
            continue;
        double rs = pv + (sz[v]/nkids)*ln;
        double md = (rs + pv)/2.0;

        build(v, ind, pv, rs, pos + polar(1.0, md));

        pv = rs;
    }
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd(N);
    int a,b;
    for(int i = 0; i < N-1; ++i){
        rd2(a,b);
        --a,--b;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }
    fill_sz(1, 1);
    int cent = get_centroid(1,N,1);
    fill_sz(cent, cent);
    build(cent, cent, 0.0, 2*M_PI, {0,0});
    for(int i = 0; i < N; ++i){
        printf("%.8lf %.8lf\n", X(po[i]), Y(po[i]));
    }
    return 0;
}
