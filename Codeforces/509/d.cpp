#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define rd3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define rd2(x,y) cin >> x >> y;
#define rd(x) cin >> x >> y;
#define pr3(x,y,z) printf("%d %d %d\n", x, y, z)
#define pr2(x,y) cout << x << ' ' << y << endl; 
#define pr(x) cout << x << endl; 
#define debug(x) cout << #x << " = "<< x << ' ' << endl;
using namespace std;
typedef long long ll;
typedef complex<double> cc;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
const int INFI = 1000*1000*1000;
const double EPS = 1e-8;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;
const int MX_N = 200002;
ll N,H; 
ii invals[MX_N];
ll lsum[MX_N];
struct inValTree{
    ll L, R, ind;
    inValTree *l, *r;
    inValTree(){ l = r = nullptr, ind=-1;}
    ~inValTree(){ delete l,r; }
};

inValTree* construct(ll L, ll R){
    inValTree * t = new inValTree();
    if(L==R){
        t->L = invals[L].fi;
        t->R = invals[L].se;
        t->ind = L;
        return t;
    }
    if(R<L)
        return nullptr;
    ll md = (L+R)/2;
    auto l = construct(L,md);
    auto r = construct(md+1,R);
    t->l = l;
    t->r = r;
    t->L = t->l->L;
    t->R = t->r->L;
    return t;
}

ll invalN(ll x, inValTree* root){
    if(root->ind != -1)
        return root->ind;
    if(root->r->L <= x)
        return invalN(x, root->r);
    return invalN(x, root->l);
}

bool check(ll x, int stI, inValTree * r){
    ll bs = lsum[stI];
    ll ind = invalN(x, r);
    ll drpd = (ind > 0 ? lsum[ind-1] : 0) - bs;
    drpd += min(invals[ind].se - invals[ind].fi, x - invals[ind].fi);
    return drpd >= H;
}

int main(){
    rd2(N, H);
    ll l,r;
    ll prv = 0;
    for(int i = 0; i < N; ++i){
        rd2(l,r);
        invals[i] = {prv, l};
        prv = r;
    }
    invals[N++] = {prv, INFL};
    auto root = construct(0, N-1);
    ll sm = 0;
    for(int i = 0; i < N-1;++i){
        sm += invals[i].se - invals[i].fi;
        lsum[i] = sm;
    }
    ll mx = 0;
    for(int i = 0; i < N-1; ++i){
        ll L = 1; ll R = INFL;
        ll st = invals[i].se;
        while(L < R){
            ll md = (L+R)/2;
            if(check(st + md, i, root))
                R = md;
            else
                L = md+1;
        }
        mx = max(mx, L);
    }
    pr(mx);
    delete root;
    return 0;
}
