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

struct intvl {
    int l,r;
    ll w;
};

const int MX_S = 100100;
const int MX_INTV = 3*MX_S;
vector<intvl> intvls;
int breaks[MX_S];
bool planks[MX_S];
ll dist[MX_INTV];
vi st[MX_S], nd[MX_S];
int N, M, S;

vector<ii> adjList[MX_INTV];

struct path {
    int u; ll d;
    bool operator < (const path& p) const { 
        return d > p.d;
    }
};

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd3(N,M,S);
    for(int i = 0; i < N; ++i){
        int L, R; rd2(L,R);
        --L, --R;
        breaks[L] += 1;
        breaks[R+1] -= 1;
    }
    int cnt = 0;
    for(int i = 0; i < S; ++i){
        cnt += breaks[i];
        if(cnt)
            planks[i] = false;
        else
            planks[i] = true;
    }
    int L = 0;
    for(int i = 1; i < S; ++i){
        if(!planks[i] && planks[i-1])
            intvls.pb({L, i-1, 0});
        if(planks[i] && !planks[i-1])
            L = i;
    }
    if(planks[S-1])
        intvls.pb({L, S-1, 0});
    for(int i = 0; i < M; ++i){
        int A, B; ll C; rd3(A,B,C);
        --A, --B;
        intvls.pb({A,B,C});
    }
    for(int i = 0; i < sz(intvls); ++i){
        st[intvls[i].l].pb(i);
        nd[intvls[i].r].pb(i);
    }
    set<int> open;
    int cap = sz(intvls);
    for(int i = 0; i < S; ++i){

        if(sz(st[i])){
            int inter = cap++;
            for(int u : open)
                adjList[u].pb({inter, 0});
            for(int v : st[i]){
                adjList[inter].pb({v, intvls[v].w});
                open.insert(v);
            }
        }

        for(int v : nd[i]){
            open.erase(v);
        }
    }
    for(int i = 1; i < S; ++i){
        if(sz(st[i]) == 0 || sz(nd[i-1]) == 0)
            continue;
        int inter = cap++;
        for(int u : st[i]){
            adjList[u].pb({inter, 0});
        }
        for(int v : nd[i-1]){
            adjList[inter].pb({v, intvls[v].w});
        }
    }
    int source = cap + 2;
    int T = source + 1;
    for(int i = 0; i < sz(intvls); ++i){
        if(intvls[i].l == 0)
            adjList[source].pb({i,intvls[i].w});
        if(intvls[i].r == S-1)
            adjList[i].pb({T,0});
    }

    dbg(
    for(int i = 0; i < sz(intvls); ++i){
        if(adjList[i].size() == 0)
            continue;
        printf("[%d,%d] -> : ", intvls[i].l, intvls[i].r);
        for(ii v : adjList[i]){
            if(v.fi == T)
                printf("T ");
            else
                printf("([%d,%d], %d) ", intvls[v.fi].l, intvls[v.fi].r, v.se);
        }
        putchar('\n');
    }
    );

    for(int i =0; i <= T; ++i)
        dist[i] = INFL;
    dist[source] = 0;
    priority_queue<path> q;
    q.push(path{source,0});
    while(!q.empty()){
        path p = q.top(); q.pop();
        int u = p.u; ll d = p.d;
        if(dist[u] < d)
            continue;
        for(auto v : adjList[u]){
            ll nd = d + v.second;
            if(nd < dist[v.first]){
                dist[v.first] = nd;
                q.push(path{v.first,nd});
            }
        }
    }
    pr(dist[T]);
    return 0;
}
