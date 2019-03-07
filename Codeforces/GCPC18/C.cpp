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
int N, M;
vector<ii> adjList[MX_N];
int memo[MX_N];

int trav(int u){
    if(memo[u] != -1)
        return memo[u];
    int mx = 0;
    for(auto& i : adjList[u]){
        mx = max(mx, i.se + trav(i.fi));
    }
    return memo[u] = mx;
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    memset(memo,-1,sizeof(memo));
    rd2(N,M);
    int s,t,c;
    for(int i = 0; i < M; ++i){
        rd3(s,t,c);
        --s,--t;
        adjList[s].pb({t,c});
    }
    int mx = 0;
    for(int i = 0; i < N; ++i)
        mx = max(mx, trav(i));
    pr(mx);
    return 0;
}
