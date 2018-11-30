#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) ((int) x.size())
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

struct cvxH{
    vector<ll> A;
    vector<ll> B;

    int ptr;

    cvxH():ptr(0){}

    // a descends
    void addLine(ll a, ll b){ // intersection of (A[len-2],B[len-2]) with (A[len-1],B[len-1]) must lie to the left of intersection of (A[len-1],B[len-1]) with (a,b)
        while (sz(A) >= 2 && (B[sz(B) - 2] - B[sz(B) - 1]) * (a - A[sz(A) - 1]) >= (B[sz(B) - 1] - b) * (A[sz(A) - 1] - A[sz(A) - 2])) {
            A.pop_back();
            B.pop_back();
        }
        A.pb(a);
        B.pb(b);
    }
    // x ascends
    ll minValue(ll x) {
      ptr = min(ptr, sz(A) - 1);
      while (ptr + 1 < sz(A) && A[ptr + 1] * x + B[ptr + 1] <= A[ptr] * x + B[ptr]) {
        ++ptr;
      }
      return A[ptr] * x + B[ptr];
    }
};

template<class T>
struct SegTree {
    int size;
    vector<int> tree;
    vector<T> data;

    template <class ForwardIt>
    SegTree(ForwardIt first, ForwardIt last) : size(distance(first, last)) {
        tree.resize(4*size+2);
        data.resize(size);
        int i = 0; auto j = first;
        for(; j!=last; i++, j++)
            update(1, 0, size-1, i, *j);
    }

    SegTree() : size(0) {}

    void update(int p, int L, int R, int ind, const T& v) {
        if(L==R){
            data[ind] = v;
            tree[p] = ind;
            return;
        }
        int md = (L+R)/2;
        if(ind <= md)
            update(2*p,L,md,ind,v);
        else
            update(2*p+1,md+1,R,ind,v);
        tree[p] = (data[tree[2*p]] < data[tree[2*p+1]] ? tree[2*p] : tree[2*p+1]);
    }

    int rmq(int l, int r){
        return rmq(1, l, r, 0, size-1);
    }

    int rmq(int p, int l, int r, int lb, int rb){
        if(rb < l || lb > r)
            return -1;
        if(lb >= l && rb <= r)
            return tree[p];
        int md = (lb+rb)/2;
        int a = rmq(2*p, l, r, lb, md);
        int b = rmq(2*p+1, l, r, md+1, rb);
        if(a<0) return b;
        if(b<0) return a;
        return (data[a] < data[b] ? a : b);
    }
};

const int MX_N = 200002;
const int VIND_MX = 2*MX_N;
vector<pair<int, ll> > adjList[MX_N];
vi centAdj[MX_N];
int N, sz[MX_N], centP[MX_N];
ll pen[MX_N];
bool mkd[MX_N];
vector<pair<ll, ll> > dists[MX_N];
cvxH hulls[MX_N];
int H[MX_N], E[VIND_MX], L[VIND_MX];
ll hangDist[MX_N];
int vind = 0;
int prm[MX_N];
SegTree<int> tree;

/*
 * H[u] is first visit of u
 * E[x] is vertex at time x
 * L[x] is depth at time x
 */
void vis(int u, int d){
    H[u]=vind;
    E[vind] = u;
    L[vind++] = d;
    for(auto& i : adjList[u]){
        if(H[i.fi]!=-1)
            continue;
        vis(i.fi,d+1);
        E[vind] = u;
        L[vind++] = d;
    }
}

int LCA(int u, int v){
    if(H[u] > H[v]){
        int t = u;
        u = v;
        v = t;
    }
    //run some range min query on L
    //between H[u] and H[v]
    int ind = tree.rmq(H[u],H[v]);
    return E[ind];
}

ll dist(int u, int v){
    int ind = LCA(u,v);
    ll f = abs(hangDist[ind]-hangDist[u])
        + abs(hangDist[ind]-hangDist[v]);
    assert(f >= 0LL);
    return f;
}

void fill_sz(int u, int p){
    sz[u] = 1;
    for(auto& v : adjList[u]){
        if(v.fi==p || mkd[v.fi])
            continue;
        fill_sz(v.fi,u);
        sz[u]+=sz[v.fi];
    }
}

int get_centroid(int u, int n, int p){
    for(auto& v : adjList[u]){
        if(v.fi==p || mkd[v.fi])
            continue;
        if(sz[v.fi] > n/2)
            return get_centroid(v.fi, n, u);
    }
    return u;
}

int decomp(int u){
    fill_sz(u, -1);
    int cent = get_centroid(u, sz[u], -1);
    mkd[cent] = true;
    for(auto& v : adjList[cent]){
        if(mkd[v.fi])
            continue;
        int r = decomp(v.fi);
        centP[r] = cent;
        centAdj[cent].pb(r);
    }
    return cent;
}

void fill_dists(int u, int x, int p, ll sm){
    dists[x].pb({pen[u], sm});
    for(auto& v : adjList[u]){
        if(v.fi == p || mkd[v.fi])
            continue;
        fill_dists(v.fi, x, u, sm+v.se);
    }
}

void travCent(int u){
    fill_dists(u, u, -1, 0);
    mkd[u]=true;
    for(int v : centAdj[u])
        travCent(v);
}

void fill_hang_dist(int u, int p, ll sm){
    hangDist[u] = sm;
    for(auto& v : adjList[u])
        if(v.fi != p)
            fill_hang_dist(v.fi, u, sm+v.se);
}

ll climb(int u){
    ll x = pen[u];
    ll mn = x*x;
    int c = u;
    while(c != -1){
        mn = min(mn, dist(u, c) + hulls[c].minValue(x));
        c = centP[c];
    }
    return mn;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    memset(H, -1, sizeof(H));
    rd(N);
    for(int i = 0; i < N; ++i)
        rd(pen[i]);
    int x,y;
    ll w;
    for(int i = 0; i < N-1; ++i){
        rd3(x,y,w);
        --x,--y;
        adjList[x].pb({y,w});
        adjList[y].pb({x,w});
    }

    fill_hang_dist(0, 0, 0LL);

    vis(0, 0);
    tree = SegTree<int>(L, L+vind);

    int centRoot = decomp(0);
    centP[centRoot] = -1;
    memset(mkd, 0, sizeof(mkd));
    travCent(centRoot);
    for(int i = 0; i < N; ++i){
        sort(dists[i].begin(), dists[i].end(), greater<pair<ll,ll> >());
        for(const auto& p : dists[i])
            hulls[i].addLine(p.fi,p.se);
    }
    for(int i = 0; i < N; ++i)
        prm[i] = i;
    sort(prm, prm+N, [](int a, int b){return pen[a] < pen[b];});
    ll sm = 0;
    for(int i = 0; i < N; ++i)
        sm += climb(prm[i]);
    pr(sm);
    return 0;
}
