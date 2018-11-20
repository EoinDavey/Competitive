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
int N, K, M;
vi mList[MX_N];
vector<ii> tList[MX_N];
int compN[MX_N];

void fill(int u, int c){
    compN[u] = c;
    for(int v : mList[u])
        if(compN[v]==0)
            fill(v,c);
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd3(N,K,M);
    int u,v,w;
    for(int i = 0; i < K; ++i){
        rd2(u,v);
        mList[u].pb(v);
        mList[v].pb(u);
    }
    for(int i= 0; i < M; ++i){
        rd3(u,v,w);
        tList[u].pb({v, w});
        tList[v].pb({u, w});
    }
    for(int i= 1;i <= N; ++i)
        if(compN[i]==0)
            fill(i,i);
    return 0;
}
