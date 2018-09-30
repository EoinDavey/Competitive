#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int MX_N = 505;
ll memo[MX_N][MX_N];
ll fac(int x){
    ll o = 1;
    for(int i = 2; i <= x; ++i)
        o *= ((ll)i);
    return o;
}

ll nckmemo[MX_N][MX_N];
ll nck(int n, int k){
    if(nckmemo[n][k]!=-1)
        return nckmemo[n][k];
    if(n==0)
        return k==0;
    if(k==0)
        return 1;
    return nckmemo[n][k] = nck(n-1,k) + nck(n-1,k-1);
}

void pr(int x){for(int i = 0; i < x;++i)putchar(' ');}
ll rec(int N, int X){
    if(N==0)
        return 1;
    if(X==0)
        return N==1;
    if(memo[N][X]!=-1)
        return memo[N][X];
    ll s=0LL;
    for(int a = 0; a < N; a++){
        int b = N-1-a;
        s += nck(N-1,a) * rec(a,X-1) * rec(b,X-1);
    }
    return memo[N][X] = s;
}

int main(){
    int T; scanf("%d",&T);
    memset(memo,-1,sizeof(memo));
    memset(nckmemo,-1,sizeof(nckmemo));
    while(T-->0){
        int N; scanf("%d",&N);
        ll tways = 0;
        double avg = 0.0;
        ll pv = 0.0;
        for(int i = 0; i < N; ++i){
            ll w = rec(N,i);
            avg += i*(w-pv);
            pv = w;
        }
        avg/=pv;
        printf("%.8lf\n",avg);
    }
    return 0;
}
