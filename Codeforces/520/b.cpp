#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int MX_N = 1000 * 1000  + 2;
bool sieve[MX_N];

int main(){
    int N;scanf("%d",&N);
    vector<ll> primes;
    for(int i = 2; i < MX_N; ++i){
        if(!sieve[i]){
            primes.pb(i);
            for(int j = i*2; j < MX_N; j+=i)
                sieve[j] = true;
        }
    }
    if(!sieve[N]){
        printf("%d 0\n",N);
        return 0;
    }
    ll ans = 1;
    for(ll p : primes)
        if(N%p==0)
            ans*=p;
    int cnt = 0;
    int oans = ans;
    while(ans < N){
        ans*=ans;
        cnt++;
    }
    if(ans != N)
        cnt+=1;
    printf("%d %d\n", oans, cnt);
    return 0;
}
