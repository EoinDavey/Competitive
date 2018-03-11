#include<bits/stdc++.h>
using namespace std;

const int MX_N = 14;
const int MX_SZ = (1<<14);

int N;
int memo[MX_N][MX_SZ];
int hands[MX_N][4];

map<int,string> mp;
bool dp(int p, int st){
	if(p==N)
		return st == (1<<13)-1;
	if(memo[p][st]!=-1)
		return memo[p][st];
	for(int i = 0; i < 4; ++i){
		if((st&(1<<hands[p][i]))==0){
			if(dp(p+1,st|(1<<hands[p][i])))
				return memo[p][st] = true;
		}
	}
	return memo[p][st] = false;
}

void pr(int p, int st){
	if(p==N)
		return;
	for(int i = 0; i < 4; ++i){
		if((st&(1<<hands[p][i]))==0){
			if(dp(p+1,st|(1<<hands[p][i]))){
				if(mp[hands[p][i]]=="")
					cout << hands[p][i]+2;
				else
					cout << mp[hands[p][i]];
				if(p!=N-1)
					cout << " ";
				pr(p+1,st|(1<<hands[p][i]));
				return;
			}
		}
	}
}

int val(const string &a){
	if(a == "J")
		return 9;
	if(a == "Q")
		return 10;
	if(a == "K")
		return 11;
	if(a == "A")
		return 12;
	int out = 0;
	for(char c : a){
		out = out*10 + (c-'0');
	}
	return out-2;
}

int main(){
	N = 13;
	string tmp;
	memset(memo,-1,sizeof(memo));
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < 4; ++j){
			cin >> tmp;
			hands[i][j] = val(tmp);
		}
		sort(hands[i],hands[i]+4,greater<int>());
	}
	mp[9]="J";
	mp[10]="Q";
	mp[11]="K";
	mp[12]="A";
	dp(0,0);
	pr(0,0);
	cout << '\n';
	return 0;
}
