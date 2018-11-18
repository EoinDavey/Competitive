#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define X(x) real(x)
#define Y(x) imag(x)
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
double a,b,c;

vector<cc> gpts(cc p){
    vector<cc> pts;
    double nx = (c - b*Y(p))/a;
    pts.pb({nx,Y(p)});
    double ny = (c - a*X(p))/b;
    pts.pb({X(p),ny});
    return pts;
}

double bst(cc A, cc B){
    auto apts = gpts(A);
    auto bpts = gpts(B);
    double mn = 1e20;
    for(auto p : apts)
        for(auto q : bpts)
            mn = min(mn, abs(A-p) + abs(p-q) + abs(B-q));
    return mn;
}

int main(){
    //ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    c*=-1;
    ll x1,x2,y1,y2;
    cc A,B;
    cin >> x1 >> y1 >> x2 >> y2;
    A = {x1,y1};
    B = {x2,y2};
    double mn = abs(x1-x2) + abs(y1-y2);
    if(a==0.0 || b==0.0){
        cout <<fixed<<setprecision(10)<< mn << endl;
        return 0;
    }
    mn = min(mn, bst(A,B));
    cout << fixed << setprecision(10) << mn << endl;
    return 0;
}
