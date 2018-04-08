#include<bits/stdc++.h>
using namespace std;
typedef complex<double> cc;
const double l = sqrt(2)/2.0;

int main(){
    int T; scanf("%d",&T);
    for(int t = 1; t <= T; ++t){
        printf("Case #%d:\n",t);
        double A; scanf("%lf",&A);
        double ang = acos((A/2.0)/l);
        cc r = polar(l,ang);
        cc l = -r;
        cc a = polar(1.0,ang-(M_PI/4));
        cc crnr = l+a;
        cc p1 = (l+crnr)/2.0;
        cc p2 = (r+crnr)/2.0;
        printf("%lf %lf 0\n%lf %lf 0\n",real(p1),imag(p1),real(p2),imag(p2));
        puts("0 0 0.5");
    }
    return 0;
}
