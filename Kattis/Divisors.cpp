#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
constexpr int N = 433;
bool sieve[N];
vector<ll> primes;

int main(){
  for(int i = 2; i < N; ++i){
    if(!sieve[i]){
      primes.push_back(i);
      for(int j = 2*i; j < N; j+=i)
          sieve[j]=true;
    }
  }

  int nPrimes = primes.size();

  vector<ll> primeFacs[N];
  primeFacs[0].assign(N, 0);
  primeFacs[1].assign(N, 0);

  for(int i = 2; i < N; ++i){
      int t = i;
      ll p = i;
      vector<ll> facs(nPrimes, 0);
      for(int j = 0; j < nPrimes; ++j){
        while(p % primes[j] == 0){
          p /= primes[j];
          facs[j]+=1;
        }
      }
      primeFacs[t] = std::move(facs);
  }

  int n,k;
  while(scanf("%d %d", &n, &k) == 2) {
    vector<ll> val(nPrimes,0);

    for(int x = n-k+1; x < n+1; ++x)
      for(int i = 0; i < nPrimes; ++i)
        val[i]+=primeFacs[x][i];

    for(int x = 1; x < k+1; ++x)
      for(int i = 0; i < nPrimes; ++i)
        val[i]-=primeFacs[x][i];

    ll out = 1;
    for(int i = 0; i < nPrimes; ++i)
      out*=(val[i]+1);
    printf("%lld\n", out);
  }
}
