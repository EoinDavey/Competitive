#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
#define endl '\n'

int prices[11][101];
int ks[11];
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};
unordered_map<pair<int, int>, int, pair_hash> dp;
int num_components;

int process(int money_left, int idx) {
	if(money_left < 0)
		return -1000000001;
	if(idx == num_components)
		return 0;
	if(dp.find({money_left, idx}) != dp.end())
		return dp[{money_left, idx}];
	int answer = -1000000001;
	for(int part = 0; part < ks[idx]; part++) {
		int returned = process(money_left - prices[idx][part], idx + 1);
		if(returned != -1000000001)
			answer = max(answer, returned + prices[idx][part]);
	}
	return dp[{money_left, idx}] = answer;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		dp.clear();
		int money;
		cin >> money >> num_components;
		for(int i = 0; i < num_components; i++)
			cin >> ks[i];
		for(int i = 0; i < num_components; i++) {
			for(int j = 0; j < ks[i]; j++) {
				cin >> prices[i][j];
			}
		}
        int msm = 0;
        for(int i = 0; i < num_components; ++i){
            int mn = prices[i][0];
            for(int j = 0; j < ks[i]; ++j)
                mn = min(mn, prices[i][j]);
            msm += mn;
            for(int j = 0; j < ks[i]; ++j)
                prices[i][j] -= mn;
        }
        if(money <= msm)
            cout << 0 << endl;
        else
            cout << process(money-msm, 0)+msm << endl;
	}
}
