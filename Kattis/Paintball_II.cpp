#include<bits/stdc++.h>
using namespace std;
typedef complex<double> cc;

constexpr int MX_N = 1001;
constexpr double EPS = 1e-6;

cc p[MX_N];
double r[MX_N];
int N;
bool fail = false;
bool vis[MX_N];
double wy = 1000.0;
double ey = 1000.0;

void check(int u){
    vis[u] = true;
    if(imag(p[u]) - r[u] < 0.0){
        fail = true;
        return;
    }
    for(int i = 0; i < N; i++)
        if(!vis[i] && abs(p[u]-p[i]) < r[i]+r[u])
            check(i);
    if(real(p[u]) - r[u] < 0.0){
        double yicept = imag(p[u]) - sqrt(pow(r[u],2) - pow(real(p[u]),2));
        wy = min(wy,yicept);
    }
    if(real(p[u]) + r[u] > 1000.0){
        double yicept = imag(p[u]) - sqrt(pow(r[u],2) - pow(1000.0 - real(p[u]),2));
        ey = min(ey,yicept);
    }
}

int main(){
    scanf("%d",&N);
    double _x,_y;
    for(int i = 0; i < N; ++i){
        scanf("%lf %lf %lf",&_x,&_y,&r[i]);
        p[i] = cc(_x,_y);
    }
    for(int i = 0; i < N; ++i)
        if(imag(p[i]) + r[i] > 1000.0)
            check(i);
    if(fail)
        puts("IMPOSSIBLE");
    else
        printf("%.2lf %.2lf %.2lf %.2lf\n",0.00,wy,1000.0,ey);
    return 0;
}
