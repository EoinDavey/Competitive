#include<bits/stdc++.h>
using namespace std;

const int MX_N = 25;
int N;
const double INF = 10e20;
const double EXP = 10e-8;
double lb[MX_N];
double tx[MX_N];

double calculate(double x){
    double t = x;
    double out = 0.0;
    for(int i = N; i >= 0; i--){
        if(t < lb[i])
            continue;
        out += (1-tx[i])*(t-lb[i]);
        t = lb[i];
    }
    return out;
}

double search(double L, double R, double target){
    double mid = (L+R)/2.0;
    double res = calculate(mid);
    if(abs(res - target)<EXP) return mid;
    if(target < res){
        return search(L, mid, target);
    } else return search(mid, R, target);
}

int main(){
    scanf("%d",&N);
    double u,p;
    double lim = 0;
    for(int i = 0; i < N; i++){
        scanf("%lf %lf",&u,&p);
        p = p/100.0;
        lb[i] = lim;
        tx[i] = p;
        lim+=u;
    }
    scanf("%lf",&tx[N]);
    lb[N] = lim;
    tx[N] /= 100.0;
    int C;
    scanf("%d",&C);
    double start,in;
    for(int i = 0; i < C; i++){
        scanf("%lf %lf",&start,&in);
        double taxedIn = calculate(start);
        printf("%.10lf\n",search(0,INF,taxedIn+in) - start);
    }
    return 0;
}
