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
#define X(x) real(x)
#define Y(x) imag(x)
using namespace std;
typedef long long ll;
typedef complex<double> cc;
typedef pair<int, int> ii;
typedef vector<int> vi;
const double EPS = 1e-10;
const int INFI = 1000*1000*1000;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;

const int MX_N = 2505;

typedef cc pt;
typedef vector<pt> poly;

int N, K;
double nd[MX_N];

double cross(const pt& a, const pt& b){
  return X(a) * Y(b) - Y(a) * X(b);
}

double area(const poly& p){
  double sm = 0.0;
  for(int i = 0; i < p.size(); ++i)
    sm += cross(p[i], p[(i+1)%p.size()]);
  return abs(sm/2.0);
}

void precalc(){
  double sm = 0.0;
  for(int d = 0; d < K; d++)
    sm -= log((double) (N-d));
  for(int i = 0; i < K-2; ++i)
    sm += log((double) N - 2 - i);
  sm += log((double) K) + log((double) K-1);
  nd[2] = exp(sm);
  for(int d = 3; N - d >= 0; ++d ){
    sm -= log((double) N - (d-1));
    sm += log((double) N - d - (K-3));
    nd[d] = exp(sm);
    if(abs(nd[d]) <= EPS)
      break;
  }
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  rd2(N, K);
  double x,y;
  poly p;
  for(int i = 0; i < N; ++i){
    rd2(x, y);
    p.pb({x,y});
  }
  double oA = area(p);
  double A = oA;
  precalc();
  for(int i = 0; i < N; ++i){
    //printf("Edge start %d\n", i);
    double arsm = 0.0;
    for(int stp = 1; i + stp < N; ++stp){
      arsm -= cross(p[i+stp-1], p[i]);
      arsm += cross(p[i+stp-1], p[i+stp]);
      arsm += cross(p[i+stp], p[i]);

      double aA = abs(arsm)/2.0;
      double aB = oA - aA;

      /*
      printf("\tEdge end %d\n", i+stp);
      printf("\tInside A: %lf, Outside A:%lf\n", aA, aB);
      */

      A -= nd[stp+1] * aA;
      A -= nd[N - (stp + 1) + 2] * aB;
    }
  }
  pr(fixed << setprecision(10) << A);
  return 0;
}
