#include<bits/stdc++.h>
#define X(c) real(c)
#define Y(c) imag(c)
using namespace std;
typedef complex<double> cc;
typedef vector<cc> poly;

double cross(cc a, cc b){ return X(a)*Y(b) - Y(a)*X(b);}
double area(const poly& p){
    double a = 0.0;
    for(int i = 0; i < p.size(); ++i)
        a+=cross(p[i], p[(i+1)%p.size()]);
    return abs(a)/2.0;
}

poly nPoly(const poly& p, double s){
    poly np;
    double r  = 1.0/s;
    for(int i = 0; i < p.size(); ++i){
        np.push_back(p[i] + r*(p[(i-1+p.size())%p.size()] - p[i]));
        np.push_back(p[i] + r*(p[(i+1)%p.size()] - p[i]));
    }
    return np;
}

int main(){
    double a;
    int N;scanf("%lf %d", &a, &N);
    double x,y;
    poly p;
    for(int i = 0; i < N; ++i){
        scanf("%lf %lf", &x, &y);
        p.push_back({x,y});
    }
    double A = area(p);
    double B = area(nPoly(p,2.0));
    x = 2.0*sqrt((A-B)/((1-a)*A));
    printf("%.6lf\n", x);
    return 0;
}
