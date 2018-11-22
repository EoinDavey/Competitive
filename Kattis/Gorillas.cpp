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

const int MX_N = 1001;
double X1,Y1,X2,Y2;
int N;
vector<pair<double, double> > bds;
double aug[MX_N][MX_N+1], col[MX_N];

void gauss(double mat[MX_N][MX_N+1], double ans[MX_N], int n){
    int i,j,k,l;double t;

    for(j = 0; j < n-1; ++j){
        l = j;
        for(i = j+1; i < n; ++i){
            if(fabs(mat[i][j]) > fabs(mat[l][j]))
                l=i;
        }
        for(k = j; k <= n; ++k)
            t=mat[j][k],mat[j][k]=mat[l][k],mat[l][k]=t;
        for(i = j+1; i < n; ++i)
            for(k = n; k >= j; --k)
                mat[i][k] -= mat[j][k] * mat[i][j] / mat[j][j];
    }

    for(j = n-1; j >= 0; --j){
        for(t=0.0, k = j+1;k<n;++k)
            t += mat[j][k] * ans[k];
        ans[j] = (mat[j][n] - t) / mat[j][j];
    }
}

void solve(double x, double y, double& a, double& b){
    aug[0][0] = x*x; aug[0][1] = x; aug[0][2] = y;
    aug[1][0] = X2*X2; aug[1][1] = X2; aug[1][2] = Y2;

    gauss(aug, col, 2);
    a = col[0];
    b = col[1];
}

inline double f(double x, double a, double b){ return a*x*x + b*x;}

double ternary_search(double l, double r, double a,double b) {
    while (r - l > EPS) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1, a,b);      //evaluates the function at m1
        double f2 = f(m2, a,b);      //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return f(l,a,b);
}

double h(double a, double b){
    return ternary_search(0.0, X2, a, b);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T; rd(T);
    while(T-->0){
        cin >> X1 >> Y1 >> X2 >> Y2;
        X2 -= X1;
        Y2 -= Y1;
        rd(N);
        bds.clear();
        for(int i = 0; i < N; ++i){
            double x,y;
            rd2(x,y);
            bds.pb({x,y});
        }
        double mx = max(0.0, Y2);
        double x,y, a,b ;
        for(const auto& bd : bds){
            x=bd.fi-X1;
            y=bd.se-Y1;
            solve(x,y,a,b);
            mx = max(mx, h(a,b));
        }
        pr(fixed<<setprecision(10) << mx+Y1);
    }
    return 0;
}
