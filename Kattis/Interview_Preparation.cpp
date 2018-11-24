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

typedef pair<double, double> dd;
typedef vector<dd> vdd;
double A, B, ta, tb, T;
vdd pts;
int C;
double xcap, ycap;

inline double x(double b){ return A + (T - tb*(b-B))/ta; }

inline double y(double b){ return B + (T - ta*(b-A))/tb; }

vdd genxInvals(){
    vdd o;
    for(const auto& d : pts){
        double lx = min(xcap, x(d.se)+EPS);
        double ly = min(ycap, y(d.fi)+EPS);
        if(lx >= d.fi && ly >= d.se){
            o.pb({d.fi, lx});
        }
    }
    return o;
}

int mxOv(const vdd& o){
    vector<pair<double, bool> > evs;
    for(const auto& i : o){
        evs.pb({i.fi, 0});
        evs.pb({i.se, 1});
    }
    sort(evs.begin(), evs.end());
    int cnt = 0;
    int mx = 0;
    for(const auto& e : evs){
        if(e.se)
            cnt-=1;
        else
            cnt+=1;
        mx = max(mx, cnt);
    }
    return mx;
}

int solve(){
    auto xIv = genxInvals();
    return mxOv(xIv);
}

int main(){
    cin >> A >> B >> T >> ta >> tb;
    xcap = x(B);
    ycap = y(A);
    rd(C);
    double a,b;
    for(int i = 0; i < C; ++i){
        rd2(a,b);
        pts.pb({a,b});
    }
    pr(solve());
    return 0;
}
