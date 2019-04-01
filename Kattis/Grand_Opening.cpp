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

const int MX_N = 10010;
const int MX_M = 50010;
int N, M;

map<string, int> indMp;
int ideg[MX_N];
int odeg[MX_N];
int p[MX_N];
vi adjList[MX_N];
bool vis[MX_N];

int cmpCnt;
int find(int i) {return p[i] = (i == p[i] ? i : find(p[i])); }
int join(int a, int b){
  a = find(a);
  b = find(b);
  if(a != b)
    p[a] = b, cmpCnt--;
}

int ind(const string& s){
  if(indMp.count(s))
    return indMp[s];
  return indMp[s] = indMp.size();
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd2(N,M);
    string a,b;
    int x, ia, ib;
    bool wr = false;
    cmpCnt = 0;
    for(int i = 0; i < N; ++i)
      p[i] = i;
    for(int i = 0; i < N; ++i){
      rd2(a, x);
      ia = ind(a);
      while(x-->0){
        rd(b);
        if(a == b)
          continue;
        wr = true;
        ib = ind(b);
        ++odeg[ia];
        ++ideg[ib];
        adjList[ia].pb(ib);
        join(ia, ib);
      }
    }
    if(!wr){
      pr("FALSE ALARM");
      return 0;
    }
    for(int i = 0; i < N; ++i)
      if(ideg[i] || odeg[i])
        ++cmpCnt;
    bool f = false;
    if(cmpCnt != 1)
      f = true;
    int ocnt = 0;
    int icnt = 0;
    for(int i = 0; i < N && !f; ++i){
      if(ideg[i] == odeg[i])
        continue;
      if(ideg[i] == odeg[i] + 1)
        icnt += 1;
      else if(ideg[i] == odeg[i] - 1)
        ocnt += 1;
      else
        f = true;
    }
    if(ocnt > 1 || icnt > 1)
      f = true;
    if(!f)
      pr("POSSIBLE");
    else
      pr("IMPOSSIBLE");
    return 0;
}
