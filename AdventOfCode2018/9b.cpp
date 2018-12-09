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

const int MX_N = 1000; //TODO

struct link{
    ll v;
    link * prev, * next;
};

link* insert(ll x, link * l){
    link *wlk = l->next;
    link *n = new link{};
    n->v = x;
    n->prev = wlk;
    n->next = wlk->next;
    n->next->prev = n;
    wlk->next = n;
    return n;
}

link* rem(ll& sc, link * c ){
    link * wlk = c;
    for(int i = 0; i < 7; ++i)
        wlk = wlk->prev;
    sc = wlk->v;
    link * r = wlk->next;
    link * p = wlk->prev;
    p->next = r;
    r->prev = p;
    return r;
}

ll scrs[500];

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    link * c = new link{};
    c->prev = c;
    c->next = c;
    c->v = 0;
    ll n, lst; scanf("%lld players; last marble is worth %lld points", &n, &lst);
    int curE=0; 
    for(ll i = 1; i <=lst+1; ++i){
        if(i%23==0){
            scrs[curE] += i;
            ll v; 
            c = rem(v, c);
            scrs[curE] += v;
        } else {
            c = insert(i, c);
        }

        curE= (curE+1)%n;
    }
    ll mx = 0;
    for(int i = 0; i < n; ++i)
        mx = max(mx, scrs[i]);
    pr(mx);
    return 0;
}
