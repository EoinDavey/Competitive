#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define pb push_back
#define ii pair<int, int>
#define fi first
#define se second
#define mk make_pair
#define mt make_tuple

#define N 1000007   //10e6 + 7

vector<int> suit[5];
vector<int>v;
vector<int>og;
vector<int>curr;
int dp[N],I[N],L[N];
const int INF = 1000*1000;



void gen(int x){
	curr.clear();
	for(int i=0; i<v.size(); i++){
		if(x&(1<<v[i]))sort(suit[v[i]].begin(), suit[v[i]].end());
		else sort(suit[v[i]].rbegin(), suit[v[i]].rend());
		for(int j=0; j<suit[v[i]].size(); j++){
			curr.pb(suit[v[i]][j]);
		}	
	}
}

/*int pdist(){
	map<int, int> pMap;
	for(int i = 0; i < og.size(); ++i)
		pMap[og[i]] = i;
	for(int i = 0; i < og.size(); ++i)
		dp[i] = 0;
	dp[0] = 1;
	int mx = 1;
	for(int i = 1; i < og.size(); ++i){
		for(int j = 0; j < i; ++j)
			if(pMap[curr[j]] < pMap[curr[i]])
				dp[i] = max(dp[i], 1+dp[j]);
		mx = max(mx, dp[i]);
	}
	return og.size() - mx;
}*/

int pdist(){
	map<int, int> pMap;
	int n = og.size();
	for(int i = 0; i < og.size(); ++i)
		pMap[og[i]] = i;
	for(int i = 1; i < n+1; ++i)
		I[i] = INF;
	I[0] = -INF;
	int mx = 1;
	for(int i = 0; i < n; ++i){
		int ind = lower_bound(I, I+n+1, pMap[curr[i]]) - I;
		I[ind] = pMap[curr[i]];
		L[i] = ind;
		mx = max(mx, ind);
	}
	return n - mx;	
}
int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		int x;
		if(s[0]>='0' and s[0]<='9')x=s[0]-'0';
		else if(s[0]=='T')x=10;
		else if(s[0]=='J')x=11;
		else if(s[0]=='Q')x=12;
		else if(s[0]=='K')x=13;
		else if(s[0]=='A')x=14;
		else assert(false);
		if(s[1]=='s'){
			og.pb(x);
			suit[0].pb(x);
		}else if(s[1]=='h'){
			og.pb(100+x);
			suit[1].pb(100+x);
		}else if(s[1]=='d'){
			og.pb(200+x);
			suit[2].pb(200+x);
		}else if(s[1]=='c'){
			og.pb(300+x);
			suit[3].pb(300+x);

		}
		
	}

	for(int i=0; i<4; i++)v.pb(i);
	int ans=10000000;
	do{
		for(int i=0; i<16; i++){
			gen(i);
			ans = min(ans, pdist());// insert function here
		}
	}while(next_permutation(v.begin(), v.end()));
	
	cout << ans << endl;
	return 0;
}
