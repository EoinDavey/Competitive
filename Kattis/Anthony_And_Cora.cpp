#include<bits/stdc++.h>
using namespace std;
const int MX_N = 1011;
double memo[MX_N][MX_N];
bool st[MX_N][MX_N];
int N, M, tot;
double ps[2*MX_N];

double f(int p, int cr){
    if(p==0)
        return 0;
    if(cr==0)
        return 1.0;
    if(st[p][cr])
        return memo[p][cr];

    int r = tot-p-cr;
    st[p][cr] = true;
    return memo[p][cr] = ps[r] * f(p, cr-1) + (1.0-ps[r]) * f(p-1, cr);
}

int main(){
    scanf("%d %d",&N,&M);
    tot = N+M;
    for(int i = 0; i < N+M-1; ++i)
        scanf("%lf", &ps[i]);
    printf("%.8lf\n", f(N,M));
}
