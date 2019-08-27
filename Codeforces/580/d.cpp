#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (x.size())
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

const int MX_N = 1000; //TODO
ll as[MX_N];
int dis[MX_N], p[MX_N];

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int N; rd(N);
    ll a, oga;
    int cnt = 0;
    vector<ll> lss[100];
    for(int i = 0; i < N; ++i){
        rd(a);
        oga = a;
        if(cnt < MX_N && a != 0LL)
            as[cnt++] = a;
        int j = 0;
        while(a){
            if(a % 2LL != 0){
                lss[j].pb(oga);
            }
            a /= 2LL;
            j+=1;
        }
    }
    for(int i = 0; i < 100; ++i){
        if(!sz(lss[i]))
            continue;
        if(sz(lss[i]) >= 3){
            pr(3);
            return 0;
        }
    }
    N = cnt;
    assert(N < 300);
    int mn = INFI;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j)
            dis[j] = INFI, p[j] = -1;
        dis[i] = 0;

        dbg(printf("Starting at %lld\n", as[i]));

        queue<int> q; q.push(i);

        while(!q.empty()){
            int u = q.front(); q.pop();
            dbg(printf("dis[%lld] = %d\n", as[u], dis[u]));
            for(int v = 0; v < N; ++v){
                if(v == u || v == p[u] || (as[u] & as[v]) == 0LL)
                    continue;
                dbg(printf("Edge to %lld\n", as[v]));
                if(dis[v] < dis[u] + 1){
                    mn = min(mn, dis[u] + dis[v] + 1);
                    break;
                }
                dis[v] = dis[u] + 1;
                p[v] = u;
                q.push(v);
            }
        }
    }
    if(mn >= INFI)
        pr(-1);
    else
        pr(mn);
    return 0;
}
