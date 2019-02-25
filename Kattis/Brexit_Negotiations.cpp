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

const int MX_N = 400004;
int N;
vi adjList[MX_N];
int e[MX_N], d[MX_N];

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd(N);
    int t, deg;
    for(int i = 0; i < N; ++i){
        rd2(e[i], deg);
        for(int j = 0; j < deg; ++j){
            rd(t);
            --t;
            ++d[t];
            adjList[i].pb(t);
        }
    }
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    for(int i = 0; i < N; ++i){
        if(d[i] == 0){
            pq.push({e[i],i});
        }
    }
    vi ord;
    while(!pq.empty()){
        ii tp = pq.top(); pq.pop();
        ord.pb(tp.se);
        for(int v : adjList[tp.se]){
            --d[v];
            if(d[v] == 0)
                pq.push({e[v], v});
        }
    }
    int cnt = 0;
    int mx = 0;
    for(auto i = ord.rbegin(); i != ord.rend(); i++){
        mx = max(mx, cnt + e[*i]);
        ++cnt;
    }
    pr(mx);
    return 0;
}
