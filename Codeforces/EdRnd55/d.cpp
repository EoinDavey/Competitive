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
int d[MX_N];
int N;
int prm[MX_N];

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd(N);
    if(N==1){
        pr("YES 0\n0");
        return 0;
    }
    int st, end;
    for(int i = 0; i < N; ++i)
        rd(d[i]), prm[i]=i;
    sort(prm, prm + N, [](int a, int b){ return d[a] < d[b];});

    vector<ii> edges;
    vi excess;
    vi chain;
    chain.pb(prm[0]);
    for(int i = 2; i < N; ++i){
        if(d[prm[i]] > 1)
            chain.pb(prm[i]);
        else
            excess.pb(prm[i]);
    }
    chain.pb(prm[1]);
    for(int i = 1; i < sz(chain); ++i){
        edges.pb({chain[i-1], chain[i]});
        --d[chain[i-1]];
        --d[chain[i]];
    }

    queue<int> q;
    for(int i = 0; i < sz(chain); ++i)
        if(d[chain[i]])
            q.push(chain[i]);

    for(int k : excess){
        if(q.empty()){
            pr("NO");
            return 0;
        }
        int j = q.front();q.pop();
        edges.pb({k, j});
        --d[k], --d[j];
        if(d[j])
            q.push(j);
    }

    pr("YES " << sz(chain)-1);
    pr(sz(edges));
    for(const auto& p : edges)
        pr(p.fi+1 << ' ' << p.se+1);
    return 0;
}
