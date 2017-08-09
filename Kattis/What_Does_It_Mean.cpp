#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;

typedef long long ll;

const int MX_N=1011;
string W;
int N,L;
string dict[MX_N];
ll nMeanings[MX_N];
int lens[MX_N];
ll memo[MX_N];
const ll MOD_7 = 1000000007;

bool matchesAt(int i, int s){
    if(lens[s] > L-i)
        return false;
    for(int j = 0; j < lens[s]; j++)
        if(dict[s][j]!=W[j+i])
            return false;
    return true;
}

ll dp(int k){
    ll ways = 0;
    if(memo[k]!=-1)
        return memo[k];
    if(k==L)
        return 1;
    if(k > L)
        return 0;
    for(int i = 0; i < N; i++) {
        if(matchesAt(k,i)){
            ways+=(nMeanings[i]*dp(k+lens[i])) % MOD_7;
            ways%=MOD_7;
        }
    }
    return memo[k] = ways;
}

int main(){
    cin >> N >> W;
    L = W.size();
    for(int i=0; i < N; i++){
        cin >> dict[i] >> nMeanings[i];
        lens[i]=dict[i].size();
    }
    memset(memo,-1,sizeof(memo));
    printf("%lld\n",dp(0));
    return 0;
}
