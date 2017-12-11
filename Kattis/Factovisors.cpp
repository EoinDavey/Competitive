#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
const int MX_SZ = 66000;
bool sieve[MX_SZ];
vector<ll> primes;

int powers(ll n, ll p){
    int rs = 0;
    for(ll x = p; x <= n; x*=p)
        rs+=n/x;
    return rs;
}

bool check(ll n, ll m){
    for(auto p : primes){
        int cnt = 0;
        while(m%p==0){
            m/=p;
            cnt++;
        }
        if(cnt > powers(n,p))
            return false;
    }
    return m <= n;
}

int main(){
    for(int i = 2; i < MX_SZ; ++i){
        if(!sieve[i]){
            primes.push_back(i);
            for(int j = i; j < MX_SZ; j+=i){
                sieve[j]=true;
            }
        }
    }
    while(scanf("%lld %lld",&n,&m)==2){
        if(m==0)
            printf("%lld does not divide %lld!\n",m,n);
        else if(m==1 || (n<=1 && m <= 1))
            printf("%lld divides %lld!\n",m,n);
        else if(!check(n,m))
            printf("%lld does not divide %lld!\n",m,n);
        else
            printf("%lld divides %lld!\n",m,n);

    }
    return 0;
}
