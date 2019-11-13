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

const int MX_N = 400000;

vi adjList[MX_N];
ll flows[MX_N], ps[MX_N];
int N;

bool verify(int u){
    if(!sz(adjList[u]))
        return true;
    int sm = 0;
    for(int v : adjList[u])
        sm += flows[v];
    return sm == flows[u];
}

void solve(int u){
    if(!sz(adjList[u]))
        return;
    for(int v : adjList[u])
        solve(v);
    int uk = 0;
    ll sm = 0;
    int ukv = 0;
    for(int v : adjList[u]){
        if(flows[v] == 0)
            ++uk, ukv = v;
        sm += flows[v];
    }

    if(flows[u]){
        if(uk == 0 && sm != flows[u]){
            pr("impossible");
            exit(0);
        } else if(uk == 1) {
            if(sm >= flows[u]){
                pr("impossible");
                exit(0);
            }
            flows[ukv] = flows[u] - sm;
            solve(ukv);
        } else if (uk > 1 && uk == flows[u] - sm) {
            for(int v : adjList[u]){
                if(flows[v] == 0){
                    flows[v] = 1;
                    solve(v);
                }
            }
        }
    } else {
        if(uk == 0){
            flows[u] = sm;
        }
    }


    /*
    if(uk > 1 && flows[u] && uk > flows[u] - sm){
        pr("impossible");
        exit(0);
    } else if(uk > 1 && flows[u] && uk == flows[u] - sm){
        for(int v : adjList[u]){
            if(flows[v] == 0){
                flows[v] = 1;
                solve(v);
            }
        }
    } else if(uk == 0 && !flows[u]){
        flows[u] = sm;
    } else if (uk == 0 && flows[u] && sm != flows[u]) {
        pr("impossible");
        exit(0);
    } else if(uk == 1 && flows[u]){
        if(sm >= flows[u]){
            pr("impossible");
            exit(0);
        }
        flows[ukv] = flows[u] - sm;
        solve(ukv);
    }
    */
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd(N);
    for(int i = 1; i < N; ++i){
        rd(ps[i]);
        adjList[ps[i]-1].pb(i);
    }
    for(int i = 0; i < N; ++i)
        rd(flows[i]);
    solve(0);
    dbg(for(int i = 0; i < N; ++i)
        printf("%d ", flows[i]);
    putchar('\n'););
    for(int i = 0; i < N; ++i){
        if(flows[i] == 0){
            pr("impossible");
            exit(0);
        }
    }
    for(int i = 0; i < N; ++i)
        if(!verify(i)){
            pr("impossible");
            exit(0);
        }
    for(int i = 0; i < N; ++i)
        pr(flows[i]);
    return 0;
}
