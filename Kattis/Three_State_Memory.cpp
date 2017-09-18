#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000009;
map<pair<ll,char>,ll> dp;

vector<ll> next_one;
string s;

ll calc(ll i, char digit){
    if(dp.count({i,digit})>0){
        return dp[{i,digit}];
    }
    if(i==0)
        return dp[{i,digit}] = 1;
    if(digit=='1')
        return dp[{i,digit}] = calc(i-1,s[i-1]);
    return dp[{i,digit}] = (calc(i-1,s[i-1]) + calc(next_one[i],'0')) % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> s;
    int nmz = 0;
    for(int i = 0; i < s.length(); ++i){
        if(s[i]=='1')
            break;
        nmz++;
    }
    s.erase(0,nmz);
    ll prev_one = 0;
    for(ll i = 0; i < s.length(); ++i){
        next_one.push_back(prev_one);
        if(s[i]=='1')
            prev_one=i;
    }
    if(s.length()==0)
        cout << 1 << endl;
    else
        cout << calc(s.length()-1,s[s.length()-1]) << endl;
    return 0;
}
