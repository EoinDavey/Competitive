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

const int MX_HW = 1002;
const int MX_N = MX_HW*MX_HW;
const int MX_TR = MX_N*3;

int h,W;
int vind;
vi adjList[MX_N];
int H[MX_N], E[MX_TR], L[MX_TR];

string board[MX_HW];

int tree[MX_TR*4 + 2];

void construct(int p, int l, int r){
    if(l==r){
        tree[p] = l;
        return;
    }
    if(r<l)
        return;
    int md = (l+r)/2;
    construct(2*p, l, md);
    construct(2*p + 1, md+1, r);
    tree[p] = L[tree[2*p]] < L[tree[2*p+1]] ? tree[2*p] : tree[2*p+1];
}

int rmq(int p, int LF, int RF, int l, int r){
    if(r < LF || l > RF)
        return INFI;
    if(l >= LF && r <= RF)
        return tree[p];
    int md = (l+r)/2;
    int lf = rmq(2*p, LF, RF, l, md);
    int rf = rmq(2*p+1 ,LF, RF, md+1, r);
    if(lf >= INFI)
        return rf;
    if(rf >= INFI)
        return lf;
    return L[lf] < L[rf] ? lf : rf;
}

/*
 * H[u] is first visit of u
 * E[x] is vertex at time x
 * L[x] is depth at time x
 */
void vis(int u, int d){
    H[u] = vind;
    E[vind] = u;
    L[vind++] = d;
    for(auto i : adjList[u]){
        if(H[i] != -1)
            continue;
        vis(i, d + 1);
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
    int ind = rmq(1, H[u], H[v], 0, vind-1);
    return E[ind];
}

ll dist(int u, int v){
    int a = H[u];
    int b = H[v];
    int ind = LCA(u,v);
    return abs(L[H[ind]]-L[a])
        + abs(L[H[ind]]-L[b]);
}

int toC(int x, int y){
    return y + x*W;
}

void join(int a, int b){
    adjList[a].pb(b);
    adjList[b].pb(a);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    rd2(h,W);
    getline(cin, board[0]);

    for(int i = 0; i <= h; ++i)
        getline(cin, board[i]);

    for(int i = 1; i <= h; ++i){
        for(int j = 1; j <= 2*W; j+=2){
            int x = i-1;
            int y = j/2;
            if(y < W-1 && board[i][j+1] == ' ')
                join(toC(x,y),toC(x,y+1));
            if(x < h-1 && board[i][j] == ' ')
                join(toC(x,y), toC(x+1,y));
        }
    }

    memset(H, -1, sizeof(H));
    vis(0, 0);
    construct(1, 0, vind - 1);

    int m; rd(m);
    int x,y;
    int pv;
    ll tot = 0;
    for(int i = 0 ; i < m; ++i){
        rd2(x, y);
        --x, --y;
        int c = toC(x,y);
        if(i)
            tot += dist(c, pv);
        pv = c;
    }
    pr(tot);
    return 0;
}
