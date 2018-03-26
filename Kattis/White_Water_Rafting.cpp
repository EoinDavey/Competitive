#include<bits/stdc++.h>
using namespace std;
typedef complex<double> point;
typedef vector<point> poly;

int Ni,No;
poly pin,pout;

double dotP(const point &a, const point &b){ return real(a)*real(b) + imag(a)*imag(b); }

double distToLine(const point &p, const point &a, const point &b){
    point ap = p-a;
    point ab = b-a;
    double u = max(0.0,min(1.0,dotP(ap,ab)/dotP(ab,ab)));
    point c = a+u*ab;
    return abs(p-c);
}

double gap(const poly &a, const poly &b){
    double mn = 1e10;
    for(const point &p : a){
        for(int i = 0; i < b.size()-1; ++i){
            double d = distToLine(p,b[i],b[i+1]);
            mn = min(d,mn);
        }
    }
    return mn;
}

int main(){
    int T; scanf("%d",&T);
    while(T-->0){
        pin.clear();
        pout.clear();
        scanf("%d",&Ni);
        double x,y;
        for(int i = 0; i < Ni;++i){
            scanf("%lf %lf",&x,&y);
            pin.push_back({x,y});
        }
        pin.push_back(pin.front());
        scanf("%d",&No);
        for(int i = 0; i < No;++i){
            scanf("%lf %lf",&x,&y);
            pout.push_back({x,y});
        }
        pout.push_back(pout.front());
        printf("%.8lf\n",min(gap(pin,pout),gap(pout,pin))/2);
    }
    return 0;
}
