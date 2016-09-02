#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

ll a[200000];
ll dp[200000];

ll f(int r){
  if(dp[r] >= 0)
    return dp[r];
  ll ma = max(f(r-1), a[r]*r+f(r-2));
  dp[r] = ma;
  return ma;
}

int main(){
  int n;
  ll ma=0;
  cin >> n;
  memset(dp,-1,sizeof(dp));
  for(int i = 0; i < n;i++){
    ll q;
    cin >> q;
    a[q]++;
    ma=max(q,ma);
  }
  cout << f(ma+1) << endl;
  return 0;
}