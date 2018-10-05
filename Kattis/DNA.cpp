#include<bits/stdc++.h>
using namespace std;
const int MX_N = 1000*1000 +2;
int N;
string s[2];
int memo[MX_N][2];

int dp(int i, bool f, int d){
    if(memo[i][f] != -1)
        return memo[i][f];
    if(i==0)
        return s[f][i]!='A';
    if(s[f][i]=='A')
        return dp(i-1, f, d+1);
    int cst = 1 + min(dp(i-1, !f, d+1),dp(i-1, f, d+1));
    return memo[i][f] = cst;
}

int main(){
    ios::sync_with_stdio(false);
    memset(memo, -1, sizeof(memo));
    cin >> N;
    cin >> s[0];
    s[1] = s[0]; for(int i = 0; i < N; ++i)s[1][i]=s[0][i]=='A' ? 'B' : 'A';
    cout << dp(N-1, 0, 0) << endl;
    return 0;
}
