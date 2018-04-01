#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX_K = 33;
const int INF = 1000*1000*1000;
ll memo[MX_K][MX_K];

ll drops(int e, int d){
    if(d==0)
        return 0LL;
    if(e==1)
        return d;
    if(memo[e][d] !=-1)
        return memo[e][d];
    return memo[e][d] = drops(e-1,d-1) + drops(e,d-1) + 1;
}

int check(ll n, int k){
    for(int j= 0; j <= 32; ++j)
        if(drops(k,j) >= n)
            return j;
    return -1;
}

int main(){
    memset(memo,-1,sizeof(memo));
    int T; scanf("%d",&T);
    while(T-->0){
        ll N; int K; scanf("%lld %d",&N,&K);
        int x = check(N,K);
        if(x==-1)
            puts("Impossible");
        else
            printf("%d\n",x);
    }
    return 0;
}
