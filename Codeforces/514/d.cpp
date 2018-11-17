#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define rd3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define rd2(x,y) scanf("%d %d", &x, &y)
#define rd(x) scanf("%d", &x)
#define pr3(x,y,z) printf("%d %d %d\n", x, y, z)
#define pr2(x,y) printf("%d %d\n", x, y)
#define pr(x) printf("%d\n", x)
#define X(c) real(c)
#define Y(c) imag(c)
using namespace std;
typedef long long ll;
typedef complex<double> cc;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INFI = 1000*1000*1000;
const int MX_N = 1000 * 100 + 1;
const double EPS = 1e-8;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;
vector<cc> pts;
int N;

inline double sq(double x) {return x*x;}
pair<double, double> inSct(const cc& c, double r, bool& suc){
    if(sq(r) < sq(Y(c)-r)){
        suc=false;
        return {0,0};
    }
    suc = true;
    double _2x1 = X(c);
    double _sqrt = sqrt(sq(r) - sq(Y(c) - r));
    //double _sqrt = sqrt(Y(c)) * sqrt(Y(c)+2*r);
    return {(_2x1-_sqrt), (_2x1+_sqrt)};
}

bool hasInsct(const vector<pair<double, double> >& lst){
    double mxS = -1e10;
    double mnE = 1e10;
    for(const auto& v : lst){
        mxS = max(mxS, v.fi);
        mnE = min(mnE, v.se);
    }
    return mxS-EPS < mnE;
}

bool check(double r){
    vector<pair<double, double > > lst;
    bool b;
    for(const auto &c : pts){
        b= true;
        auto p = inSct(c, r, b);
        if(!b)
            return false;
        lst.pb(p);
    }
    return hasInsct(lst);
}

int main(){
    rd(N);
    double x,y;
    int pos = 0;
    for(int i = 0; i < N; ++i){
        scanf("%lf %lf",&x,&y);
        pts.pb({x,y});
        pos += (y > 0);
    }
    if(pos != N && pos != 0){
        puts("-1");
        return 0;
    }
    if(pos == 0){
        for(int i = 0; i < N; ++i)
            pts[i] = conj(pts[i]);
    }
    double L = 0.0;
    double R = 1e15;
    for(int _k = 0; _k < 100; ++_k){
        double md = (L+R)/2.0;
        if(check(md))
            R = md;
        else
            L = md;
    }
    printf("%.8lf\n", L);
    return 0;
}
