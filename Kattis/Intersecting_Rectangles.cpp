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


typedef tuple<int,int,int,int> rect;
struct line {
  bool open;
  int q, l, u;
  bool operator<(const line& p) const {
    return tie(q, l, u) < tie(p.q, p.l, p.u);
  }
};
const int MX_N = 2*1000 * 100 + 10;

vi xs, ys;
vector<rect> rects;
unordered_map<int, int> xMp, yMp;
int N;
int tree[MX_N];

int LSOne(int i) { return i & (-i); }
void update(int k, int v){
  for(; k < MX_N; k+=LSOne(k))
    tree[k]+=v;
}
int query(int k){
  int sm = 0;
  for(; k; k -= LSOne(k))
    sm += tree[k];
  return sm;
}
int rngesm(int u, int v){
  assert(v >= u);
  return query(v) - query(u-1);
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd(N);
    int x1,y1,x2,y2;
    for(int i = 0; i < N; ++i){
      cin >> x1 >> y1 >> x2 >> y2;
      xs.pb(x1);
      xs.pb(x2);
      ys.pb(y1);
      ys.pb(y2);
      rects.pb(make_tuple(x1,y1,x2,y2));
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    for(int x : xs)
      xMp[x] = xMp.size() + 1;
    for(int y : ys)
      yMp[y] = yMp.size() + 1;
    vector<line> lines;
    for(const auto& r : rects){
      tie(x1, y1, x2, y2) = r;
      x1 = xMp[x1];
      x2 = xMp[x2];
      y1 = yMp[y1];
      y2 = yMp[y2];
      lines.pb({true, x1, y1, y2});
      lines.pb({false, x2, y1, y2});
    }
    sort(lines.begin(), lines.end());

    bool found = false;
    for(const auto& l : lines){
      if(l.open){
        if(rngesm(l.l, l.u)){
          found = true;
          break;
        }
        update(l.l, 1);
        update(l.u, 1);
      } else {
        update(l.l, -1);
        update(l.u, -1);
        if(rngesm(l.l, l.u)){
          found = true;
          break;
        }
      }
    }

    if(!found)
      pr(0);
    else
      pr(1);
    return 0;
}
