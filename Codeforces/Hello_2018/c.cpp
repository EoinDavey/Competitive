#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX_N=30;
ll c[MX_N];
int N,L;

ll cst(int m){
    ll s = 0;
    for(int i = 0; i < N-1; ++i)
        if((m&(1<<i))!=0)
            s+=c[i];
    s+=c[N-1]*(m>>(N-1));
    return s;
}

int main(){
    scanf("%d %d",&N,&L);
    for(int i = 0; i < N; ++i)
        scanf("%lld",c+i);
    for(int i = 1; i < N; ++i)
        c[i] = min(c[i],2LL*c[i-1]);
    ll mn = cst(L);
    for(int i = 0; i < 31; ++i){
        if((L&(1<<i))==0)
            mn = min(mn,cst((L&(~((1<<i)-1)))^(1<<i)));
    }
    printf("%lld\n",mn);
    return 0;
}
