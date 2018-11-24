#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define X(a) real(a)
#define Y(a) imag(a)
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
typedef complex<double> pt;
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;
const double EPS = 1e-8;
const int INFI = 1000*1000*1000;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;

const int MX_N = 100001;

struct circ{
    pt c;double r;
};

vector<circ> orcs;
int N,K;

inline double sq(double x){return x*x;}

vector<pt> insct(const circ& a, const circ& b){
    vector<pt> o;
    double dist = abs(a.c - b.c);
    if(dist > a.r + b.r)
        return o; //none, don't touch
    if(abs(a.r-b.r) > dist)
        return o; //none, inside
    if(abs(dist - (a.r + b.r)) < EPS){ // one intersect
        pt p = a.c + (a.r/dist)*(b.c-a.c);
        o.pb(p);
        return o;
    }
    double delta = (sq(dist) + (a.r-b.r)*(a.r+b.r))/(2.0*dist);
    pt cent = a.c + (delta/dist)*(b.c-a.c);

    double h = sqrt(sq(a.r) - sq(delta));

    pt dVec = (b.c - a.c)/dist;
    o.pb(cent + h*pt(0,1)*dVec);
    o.pb(cent + h*pt(0,-1)*dVec);
    return o;
}

bool check(double r){
    circ o{{0,0},r};
    for(int i = 0; i < N; ++i)
        orcs[i].r = r;

    vector<pair<double, bool> > ev;
    for(int i = 0; i < N; ++i){
        auto v = insct(o, orcs[i]);
        if(!sz(v))
            continue;
        if(sz(v)==1){
            double a = arg(v[0]);
            ev.pb({a-EPS,0});
            ev.pb({a+EPS,1});
        }
        if(sz(v)==2){
            double a = arg(v[0]);
            double b = arg(v[1]);
            if(a < b){
                //crossed -ve real axis
                ev.pb({b-2.0*M_PI, 0});
                ev.pb({a,1});
                ev.pb({b,0});
                ev.pb({a+2.0*M_PI, 1});
            } else {
                ev.pb({b,0});
                ev.pb({a,1});
            }
        }
    }
    sort(ev.begin(), ev.end());
    int cnt = 0;
    int mx = 0;
    for(auto & e : ev){
        if(e.se)
            cnt--;
        else
            cnt++;
        mx = max(mx, cnt);
    }
    return mx >= K;
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd2(N,K);
    double x,y;
    for(int i = 0; i < N; ++i){
        rd2(x,y);
        orcs.pb({{x,y},0});
    }
    double L = 0.0;
    double R = 10000000.0;
    while(abs(L-R)>EPS){
        double md = (L+R)/2.0;
        if(check(md))
            R = md;
        else
            L = md;
    }
    if(!check(R))
        pr("-1");
    else
        pr(fixed<<setprecision(10)<<L);
    return 0;
}
