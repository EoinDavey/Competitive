#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

long mod = 1000000007;

long dp[1000001][21][2];
long results[1000001];

long process(long polongs, long streak, bool lost_last) {
	if(polongs < 0)
		return 0;
	if(polongs == 0)
		return 1;
	if(dp[polongs][streak][lost_last] != -1)
		return dp[polongs][streak][lost_last];
	long answer = ((process(polongs - pow(2, streak), streak + 1, false) % mod) + (lost_last ? 0 : process(polongs, 0, true))) % mod;
	return dp[polongs][streak][lost_last] = (answer % mod);
}

int main() {
	memset(dp, -1, sizeof dp);
	for(int i = 0; i < 1000001; i++) {
		results[i] = process(i, 0, false);
		if(i)
			results[i] += results[i - 1];
	}
	long T;
	cin >> T;
	while(T--) {
		long a, b;
		cin >> a >> b;
		long answer = (results[b] - (a > 0 ? results[a - 1] : 0)) % mod;
		if(answer < 0) {
			answer += mod;
		}
		answer %= mod;
		cout << answer << endl;
	}
}
