#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long

using namespace std;

const ll MOD_7 = 1000000007;

ll mod(ll a, ll b){
    return ((a%b) + b)% b;
}

int main(){
    ll N,T; scanf("%lld %lld",&N,&T);
    ll a[N];
    ll A,B,C; scanf("%lld %lld %lld %lld",&A,&B,&C,&a[0]);
    for(int i = 1; i < N; i++){
        a[i] = mod((A*a[i-1] + B),C) + 1;
    }
    sort(a,a+N,less<int>());
    ll sum=0;
    ll tm=0;
    int cnt=0;
    for(int i= 0; i < N; i++){
        if(sum+a[i] <= T){
            sum  += mod(tm + a[i],MOD_7);
            tm+=a[i];
            cnt++;
        } else
            break;
    }
    printf("%d %lld\n",cnt,sum);
    return 0;
}
