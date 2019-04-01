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

const int MX_NM = 1001;
const int MX_SZ = 2022;
int res[MX_SZ][MX_SZ], N, M;
bool vis[MX_SZ];
vi adjList[MX_SZ];
int S = 0;
int T = MX_SZ - 1;

int aug(int u, int minE){
  vis[u] = true;
  if(u==T)
    return minE;
  for(int v : adjList[u]){
    if(!vis[v] && res[u][v] > 0){
      if(int f = aug(v, min(minE, res[u][v]))){
        res[u][v] -= f;
        res[v][u] += f;
        return f;
      }
    }
  }
  return 0;
}

void conn(int a, int b){
  adjList[a].pb(b);
  adjList[b].pb(a);
}

int tind(int t){ return t; }
int sind(int t){ return M + t + 1; }

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd2(N,M);
    for(int i = 1; i <= M; ++i){
      conn(S, tind(i));
      res[S][tind(i)] = 1;
    }
    for(int i = 0; i < N; ++i){
      int t, x;rd(t);
      for(int j = 0; j < t; ++j){
        rd(x);
        conn(tind(x),sind(i));
        res[tind(x)][sind(i)] = 1;
      }
      conn(sind(i),T);
      res[sind(i)][T] = 1;
    }
    int mf = 0;
    while(1){
      memset(vis, 0, sizeof(vis));
      int f = aug(S, INFI);
      if(f==0)
        break;
      mf += f;
    }
    pr(mf);
    return 0;
}
