#include<bits/stdc++.h>
using namespace std;
typedef complex<double> point;
typedef vector<point> pgon;

constexpr double INF = 1e9;
constexpr double EPS = 1e-7;

pgon genPoly(double rad, int k){
    pgon out;
    for(int i = 0; i < k; ++i){
        out.push_back(polar(rad,2*M_PI*i/(k*1.0)));
    }
    out.push_back(out[0]);
    return out;
}

double cross(const point& a, const point& b){
    return real(a) * imag(b) - imag(a) * real(b);
}

double ccw(const point& a, const point& b, const point& c){
    if(a==b || b==c || a==c)
        return false;
    point relA = b-a;
    point relC = b-c;
    return cross(relA,relC) >= 0.0;
}

double area(const pgon& poly){
    double sm = 0.0;
    for(int i = 0; i < poly.size()-1; ++i)
        sm+=cross(poly[i],poly[i+1]);
    return sm/2.0;
}

bool inPoly(const pgon& poly, const point& p){
    for(int i = 0; i < poly.size()-1; i++){
        if(!ccw(poly[i],p,poly[i+1]))
            return false;
    }
    return true;
}

bool allInPoly(const pgon& poly, const pgon& pts){
    for(auto p : pts)
        if(!inPoly(poly,p))
            return false;
    return true;
}

bool anyInPoly(const pgon& poly, const pgon& pts){
    for(auto p : pts)
        if(inPoly(poly,p))
            return true;
    return false;
}

int main(){
    int N; scanf("%d",&N);
    double x,y;
    pgon pts;
    for(int i = 0; i < N; ++i){
        scanf("%lf %lf",&x,&y);
        pts.push_back(point(x,y));
    }
    double mxans = 0.0; int mxsz;
    for(int k = 3; k <= 8; ++k){
        double L,R;
        L = 0.0; R = INF;
        while(fabs(L-R) > EPS){
            double md = (L+R)/2.0;
            if(anyInPoly(genPoly(md,k),pts))
                R = md;
            else
                L = md;
        }
        double insArea = area(genPoly(L,k));
        L = 0.0; R = INF;
        while(fabs(L-R) > EPS){
            double md = (L+R)/2.0;
            if(allInPoly(genPoly(md,k),pts))
                R = md;
            else
                L = md;
        }
        double outArea = area(genPoly(L,k));
        double ans = insArea/outArea;
        if(ans > mxans){
            mxans = ans;
            mxsz = k;
        }
    }
    printf("%d %.7lf\n",mxsz,mxans);
    return 0;
}
