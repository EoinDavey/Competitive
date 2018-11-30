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
typedef complex<double> pt;
typedef pair<int, int> ii;
typedef vector<int> vi;
const double EPS = 1e-8;
const int INFI = 1000*1000*1000;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;

const int MX_N = 1002;
#define X(a) real(a)
#define Y(a) imag(a)

struct lseg{ pt p,q;};

ll intsOn(const pt& a, const pt& b){
    pt c = b-a;
    if(X(c) < 0)
        c = -c;
    if(Y(c) < 0)
        c = conj(c);
    if(X(c)==0)
        return Y(c)+1;
    if(Y(c)==0)
        return X(c)+1;
    ll g = __gcd((ll) X(c), (ll) Y(c));
    ll f = ((ll) X(c))/g;
    return ((ll) X(c))/f + 1;
}

double cross(const pt& a, const pt& b){
    return X(a)*Y(b) - Y(a)*X(b);
}

pt insct(const lseg& a, const lseg& b, bool& fail){
    pt p = a.p;
    pt q = b.p;
    pt r = a.q-a.p;
    pt s = b.q-b.p;
    if(cross(r,s) == 0LL || cross(q-p, r)==0LL){
        fail=true;
        return {-1,-1};
    }
    double u = cross(q-p, r)/(1.0*cross(r,s));
    pt i = q+u*s;
    return i;
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int N;rd(N);
    double ax,ay,bx,by;
    vector<lseg> segs;
    for(int i = 0; i  < N; ++i){
        cin >> ax >> ay >> bx >> by;
        segs.pb({{ax,ay}, {bx,by}});
    }
    ll cnt = 0;
    bool b;
    for(int i = 0; i < N; ++i){
        ll a = intsOn(segs[i].p, segs[i].q);
        printf("Segment (%.0lf, %.0lf) -> (%.0lf, %.0lf) has %lld ints\n",
                X(segs[i].p), Y(segs[i].p), X(segs[i].q), Y(segs[i].q), a);
        cnt += a;
        for(int j = 0; j < i; ++j){
            b = false;
            pt p = insct(segs[i], segs[j],b);
            if(b)
                continue;
            printf("Segment (%.0lf, %.0lf) -> (%.0lf, %.0lf) intersects with (%.0lf, %.0lf) -> (%.0lf, %.0lf) at (%.2lf, %.2lf)\n",
                    X(segs[i].p), Y(segs[i].p), X(segs[i].q), Y(segs[i].q),
                    X(segs[j].p), Y(segs[j].p), X(segs[j].q), Y(segs[j].q),
                    X(p), Y(p));
            if(abs(X(p)-round(X(p))) < EPS && 
                abs(Y(p)-round(Y(p))) < EPS)
                --cnt;
        }
    }
    pr(cnt);
    return 0;
}
