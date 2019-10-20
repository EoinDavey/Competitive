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

const int MX_N = 100010;
const int MX_C = 10010;
int p[MX_N], N, M;
set<int> wghts;
const int RANDOM_IT = 100;

int find(int i){ return p[i] = (i == p[i] ? i : find(p[i]));}
void join(int a, int b){ p[find(a)] = find(b);}

struct edge {
    int u, v, w;
    bool operator<(const edge &rhs) const {
        if(w != rhs.w)
            return w < rhs.w;
        if(u != rhs.u)
            return u < rhs.u;
        return v < rhs.v;
    }
};
vector<edge> eMap[MX_C];
map<edge, int> cnt;

void krusk(){
    for(int i = 0; i < N; ++i)
        p[i] = i;
    int tot = 0;
    for(int w : wghts){
        // Randomise
        random_shuffle(eMap[w].begin(), eMap[w].end());
        for(const auto &e : eMap[w]){
            if(find(e.u) != find(e.v)){
                join(e.u, e.v);
                cnt[e]++;
                ++tot;
            }
        }
    }
    assert(tot == N-1);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    srand(time(NULL));
    rd2(N, M);
    int u,v,c;
    for(int i = 0; i < M; ++i){
        rd3(u,v,c);
        --u, --v;
        eMap[c].pb({u,v,c});
        wghts.insert(c);
    }
    for(int i = 0; i < RANDOM_IT; ++i)
        krusk();
    int tot = 0;
    for(const auto &i : cnt)
        if(i.se == RANDOM_IT)
            ++tot;
    pr(tot);
    return 0;
}
