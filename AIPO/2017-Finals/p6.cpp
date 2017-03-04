#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

int W;
long long memo[1001][2];
long long mod = ((long long) pow(10,9))+7;

long long dp(int width, bool corner){
    if(memo[width][corner]!=-1L)
        return memo[width][corner];
    if(width<0)return 0L;
    if(width==0&&!corner) return 1L;
    if(width==1&&!corner) return 0L;
    if(width==0&&corner) return 0L;
    if(width==1&&corner) return 1L;
    if(corner)
        return memo[width][corner] = ((dp(width-1,false)%mod) + (dp(width-2,true)%mod)) % mod;
    else return memo[width][corner] = ((dp(width-2,false)%mod) + 2L * (dp(width-1,true)%mod)) % mod;
}

int main(){
    memset(memo,-1,sizeof(memo));
    cin >> W;
    cout << dp(W,0) << endl;
    return 0;
}
