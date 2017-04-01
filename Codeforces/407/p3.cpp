#include<iostream>
#include<cstdio>
typedef long long ll;

using namespace std;

int N;

int main(){
    cin >> N;
    ll a[N];
    ll s[N];
    for(int i = 0; i < N; i++)
        scanf("%lld",&a[i]);
    for(int i = 1; i < N; i++)
        s[i] = abs(a[i]-a[i-1]);
    ll mx = abs(a[1]-a[0]);
    ll sum = 0L;
    for(int i = 1; i < N; i++){
        if(sum > mx) mx = sum;
        ll v = s[i] * ((i%2L==0L) ? -1L:1L);
        if(sum+v < 0L)
            sum = 0L;
        else sum+=v;
    }
    if(sum > mx) mx = sum;
    sum = 0L;
    for(int i = 2; i < N; i++){
        if(sum > mx) mx = sum;
        ll v = s[i] * ((i%2L==1L) ? -1L:1L);
        if(sum+v < 0L)
            sum = 0L;
        else sum+=v;
    }
    if(sum > mx) mx = sum;
    cout << mx << endl;
}
