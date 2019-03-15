#include<bits/stdc++.h>
#define ma(x,y) ((((x+y)%MOD)+MOD)%MOD)
#define mm(x,y) ((((x*y)%MOD)+MOD)%MOD)
using namespace std;
typedef long long ll;
const int MX_N = 100011;
const ll MOD = 1e9+7;
ll tree[4 * MX_N + 2];
ll d[4 * MX_N + 2];
int N, Q;

void prop(int p, int l, int r){
    tree[p] = ma(tree[p], mm(d[p], ma(ma(r,1),-l)));
    if(r>l){
        d[2*p] = ma(d[2*p], d[p]);
        d[2*p+1] = ma(d[2*p+1], d[p]);
    }
    d[p] = 0;
}

ll rsq(int p, int ql, int qr, int l, int r) {
    prop(p, l, r);
    if(r < ql || l > qr)
        return 0;
    if(l >= ql && r <= qr)
        return tree[p];
    int md = (l+r)/2;
    return ma(rsq(2*p, ql, qr, l, md)
        ,rsq(2*p+1, ql, qr, md+1, r));
}

void rng_up(int p, int ql, int qr, ll v, int l, int r){
    prop(p,l,r);
    if(r < ql || l > qr)
        return;
    if(l>=ql && r <= qr){
        d[p] = ma(d[p], v);
        prop(p,l,r);
        return;
    }
    int md=(l+r)/2;
    rng_up(2*p, ql, qr, v, l, md);
    rng_up(2*p+1, ql, qr, v, md+1,r);
    tree[p] = ma(tree[2*p], tree[2*p+1]);
}

ll rangeSum(int l, int r){
    return rsq(1, l, r, 0, N-1);
}

void rangeUpdate(int l, int r, ll v){
    rng_up(1, l, r, v, 0, N-1);
}

// a^b % md
ll modExp(ll a, int b, ll mod){
    if(b==0)
        return 1LL;
    if(b%2==0){
        ll y = modExp(a, b/2, mod);
        return (y*y)%mod;
    }
    return (a*modExp(a,b-1,mod))%mod;
}

ll modDiv(ll a, ll b, ll mod) {
    return (a * modExp(b, mod-2, mod))%mod;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> N >> Q;
    int q,u,v;
    ll S = 0.0;
    while(Q-->0){
        cin >> q;
        if(q == 1){
            cin >> u >> v;
            --u,--v;
            ll r = rangeSum(u, v);
            ll f = modDiv(1, v-u+1, MOD);
            S = ma(S,ma(1,mm(2,mm(f,r))));
            rangeUpdate(u, v, f);
        } else {
            cout << S << endl;
        }
    }
    return 0;
}
