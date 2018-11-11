#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define ma(x,y) (((x+y)%MOD + MOD)%MOD)
#define mm(x,y) ((x*y)%MOD)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const ll MOD = 1000*1000*1000 + 7;

ll fexp(ll a, ll x, ll mod){		// Fast exponenciation returns a^x % mod
	if(x==0)return 1ll;
	if(x%2==0){
		ll y=fexp(a, x/2, mod);
		return (y*y)%mod;
	}
	return (a*fexp(a, x-1, mod))%mod;
}

ll divv(ll a, ll b, ll mod){	// Division with mod returns a/b % mod
	return (a*fexp(b, mod-2, mod))%mod;
}

ll ncells(ll a[], int l){
    ll o = 1;
    for(int i = 0; i < l;++i)
        o= mm(o,a[i]);
    return o;
}

ll nadj(ll dim){
    return mm(2,dim);
}

int main(){
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while(T-->0){
        ll dim;
        cin >> dim;
        ll a[dim];
        for(int i = 0; i < dim; ++i)
            cin >> a[i];
        ll cells = ncells(a,dim);
        ll adj = nadj(dim);
        ll cellsOnBound = 0;
        ll lprod[dim], rprod[dim];
        lprod[0] = a[0];
        rprod[dim-1] = a[dim-1];

        for(int i = 1; i < dim; ++i)
            lprod[i] = mm(a[i], lprod[i-1]);
        for(int i = dim-2; i >=0; --i)
            rprod[i] = mm(a[i], rprod[i+1]);

        for(int i = 0; i < dim; ++i){
            ll v = mm(2, mm((i > 0 ? lprod[i-1] : 1),(i < dim -1 ? rprod[i+1] : 1)));
            cellsOnBound = ma(cellsOnBound, v);
        }
        ll ans = divv(ma(mm(cells,adj), -cellsOnBound), 2, MOD);
        cout << ans << endl;
    }
    return 0;
}
