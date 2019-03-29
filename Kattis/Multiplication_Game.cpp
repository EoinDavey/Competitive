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

map<ll, int> memo;
vi cur;
vi facts;
vector<ll> vals;
ll tgt;

void fac(ll n) {
  facts.clear();
  vals.clear();
  for(ll d = 2; d * d <= n; ++d){
    int x = 0;
    while(n % d == 0){
      n/=d;
      ++x;
    }
    if(x)
      facts.pb(x),vals.pb(d);
  }
  if(n > 1)
    facts.pb(1),vals.pb(n);
}

// 1 = win
// 2 = draw
// 3 = lose
int solve(ll n) {
  bool canDraw = false;
  if(memo.count(n))
    return memo[n];
  for(int i = 0; i < facts.size(); ++i){
    cur[i]++;
    ll v = n * vals[i];
    if(v == tgt){
      cur[i]--;
      return memo[n] = 1;
    }
    if(cur[i] > facts[i]){
      canDraw=true;
      cur[i]--;
      continue;
    }
    int q = solve(v);
    cur[i]--;
    if(q==2)
      canDraw=true;
    if(q==3)
      return memo[n] = 1;
  }
  if(canDraw)
    return memo[n] = 2;
  return memo[n] = 3;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int T; rd(T);
  string name;
  while(T-->0){
    memo.clear();
    rd2(tgt, name);
    fac(tgt);
    cur.clear();cur.resize(facts.size(), 0);
    int q = solve(1LL);
    if(q==2)
      pr("tie");
    else
      pr((((q==1 && name=="Bob") || (q==3 && name=="Alice")) ? "Bob":"Alice"));
  }
  return 0;
}
