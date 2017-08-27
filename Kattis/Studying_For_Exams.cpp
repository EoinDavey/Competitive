#include<bits/stdc++.h>
using namespace std;

const int MX_N = 11;
int N,T;
double a[MX_N],b[MX_N],c[MX_N];
double tot[MX_N];

double val(int u, double t){
    return a[u]*t*t + b[u]*t + c[u];
}

double deriv(int u,double t){
    return 2.0*t*a[u]+b[u];
}

int maxD(){
    int ans = 0;
    double mx = deriv(0,tot[0]);
    for(int i = 1; i < N; i++){
        double d = deriv(i,tot[i]);
        if(d > mx)
            ans = i,mx=d;
    }
    return ans;
}

int main(){
    scanf("%d %d",&N,&T);
    for(int i = 0; i < N; i++)
        scanf("%lf %lf %lf",&a[i],&b[i],&c[i]);
    double lim = (double) T;
    for(double d=0.0; d < lim; d+=0.01){
        tot[maxD()]+=0.01;
    }
    double sum = 0.0;
    for(int i = 0; i < N; i++){
        sum+=val(i,tot[i]);
    }
    sum/=(double) N;
    printf("%lf\n",sum);
    return 0;
}
