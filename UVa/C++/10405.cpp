#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

string s1,s2;

int memo[1001][1001];

int dp(int U, int V){
    if(memo[U][V]!=-1)return memo[U][V];
    if(U>=s1.size()||V>=s2.size())return 0;
    int ans;
    if(s1[U]==s2[V]){
        ans = 1 + dp(U+1, V+1);
    }else{
        ans = max(dp(U+1,V),dp(U,V+1));
    }
    return memo[U][V] = ans;
}

int main(){
    while(true){
        if(!getline(cin,s1))break;
        getline(cin,s2);
        memset(memo,-1,sizeof(memo));
        cout << dp(0,0) << endl;
    }
    return 0;
}
