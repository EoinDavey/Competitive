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

const int MX_N = 404;
vi adjList[MX_N];
bool fav[MX_N];
ll memo[MX_N];
int N;

ll dp(int u){
    if(memo[u]!=-1)
        return memo[u];
    if(!sz(adjList[u]))
        return memo[u] = fav[u];
    ll sm = 0;
    for(int v : adjList[u])
        sm+=dp(v);
    return memo[u] = sm;
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T; rd(T);
    while(T-->0){
        memset(memo, -1, sizeof(memo));
        memset(fav, -1, sizeof(fav));
        rd(N);
        int ind;
        string a;
        for(int i = 0; i < N; ++i){
            rd(ind);
            adjList[ind].clear();
            rd(a);
            if(a=="favourably")
                fav[ind]=true;
            else if(a=="catastrophically")
                fav[ind]=false;
            else{
                int _a,b,c;
                _a = stoi(a);
                rd2(b,c);
                adjList[ind].pb(_a);
                adjList[ind].pb(b);
                adjList[ind].pb(c);
            }
        }
        pr(dp(1));
    }
    return 0;
}
