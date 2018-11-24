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

const ll MOD = 1000*1000*1000 + 7;
int N;
ll x,y;

#define ma(x,y) (((x+y)%MOD + MOD)%MOD)
#define mm(x,y) (((x*y)%MOD + MOD)%MOD)

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    vector<pair<ll, bool> > evs;
    rd3(N, x, y);
    ll l,r;
    for(int i = 0; i < N; ++i){
        rd2(l,r);
        evs.pb({r, 1});
        evs.pb({l, 0});
    }
    sort(evs.begin(), evs.end());
    stack<ll> st;

    ll cst = 0;
    for(auto &ev : evs){
        if(ev.se){
            st.push(ev.fi);
        } else {
            if(st.empty()){
                cst = ma(cst, ma(x, -mm(y,ev.fi)));
            } else {
                ll v = st.top(); st.pop();
                if(y*(ev.fi - v) > x){
                    cst = ma(cst, mm(y,v));
                    cst = ma(cst, ma(x, -mm(y, ev.fi)));
                }
            }
        }
    }
    while(!st.empty()){
        ll v = st.top(); st.pop();
        cst = ma(cst, mm(y,v));
    }
    pr(cst);

    return 0;
}
