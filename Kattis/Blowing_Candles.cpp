#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define X(a) real(a)
#define Y(a) imag(a)
#define rd3(x,y,z) cin >> x >> y >> z
#define rd2(x,y) cin >> x >> y
#define rd(x) cin >> x
#define pr3(x,y,z) cout << x << ' ' << y << ' ' << z << endl
#define pr2(x,y) cout << x << ' ' << y << endl
#define pr(x) cout << x << endl
#define debug(x) cout << #x << " = "<< x << ' ' << endl
using namespace std;
typedef long long ll;
typedef complex<double> point;
typedef pair<int, int> ii;
typedef vector<int> vi;
const double EPS = 1e-8;
const int INFI = 1000*1000*1000;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;

const int MX_N = 200002;
point V[MX_N];
int N,R, perm[MX_N];
vector<int> hull;

inline double cross(const point& a, const point& b){
    return X(a)*Y(b)-Y(a)*X(b);
}

inline double dot(const point& a, const point& b){
    return X(a)*X(b)+Y(a)*Y(b);
}

//Distance from p to line (a,b)
double distToLine(const point& p, const point& a,
        const point &b){
    point ap = p-a;
    point ab = b-a;

    double u = dot(ap,ab)/dot(ab,ab);

    point c = a+ab*u; // This is the point
    return abs(c-p);
}

double ccw(const point& a, const point& b,
        const point& c){
    if(a==b || b==c || a==c)
        return false;
    point relA = b-a;
    point relC = b-c;
    return cross(relA,relC) >= 0.0;
}

int main(){
    rd2(N,R);
    double a,b;
    for(int i = 0;i < N; ++i){
        rd2(a,b);
        V[i] = {a,b};
    }
    for(int i = 0; i < N; i++){
        perm[i]=i;
    }
    sort(perm,perm+N,
            [](int a, int b){
                const point &pa = V[a];
                const point &pb = V[b];
                if(X(pa)!=X(pb))
                    return X(pa) < X(pb);
                return Y(pa) < Y(pb);
            });
    vector<int> L; vector<int> U;
    for(int i = 0; i < N;){
        int t = L.size();
        if(t >= 2 && !ccw(V[L[t-2]],V[L[t-1]],V[perm[i]]))
            L.pop_back();
        else
            L.push_back(perm[i++]);
    }
    for(int i = N-1; i >=0;){
        int t = U.size();
        if(t >= 2 && !ccw(V[U[t-2]],V[U[t-1]],V[perm[i]]))
            U.pop_back();
        else
            U.push_back(perm[i--]);
    }
    for(int i = 0; i < L.size()-1; ++i)
        hull.push_back(L[i]);
    for(int i = 0; i < U.size()-1; ++i)
        hull.push_back(U[i]);

    int pind = 1;
    double mn = 1e20;
    for(int i = 0; i < hull.size(); ++i){
        point a = V[hull[i]];
        point b = V[hull[(i+1)%sz(hull)]];
        int opind = pind%sz(hull);
        while(distToLine(V[hull[(pind+1)%sz(hull)]], a, b) + EPS >= distToLine(V[hull[pind%sz(hull)]], a, b)){
            ++pind;
            if(pind%sz(hull) == opind){
                pr(0);
                return 0;
            }
        }
        mn = min(mn, distToLine(V[hull[pind%sz(hull)]], a, b));
    }
    pr(fixed << setprecision(8) << mn);
}
