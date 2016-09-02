#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <stack>
#include <algorithm>
#include <queue>
#include <stdint.h>
using namespace std;

long long n,m,k;

long long p[5010],sum[5010],dp[5010][5010];

long long val(long long v){
	if(v>0)	return sum[v+m-1] - sum[v-1];
	else return sum[v+m-1];
}

long long d(long long k, long long v){
	if(k==0||v>n-m)return 0;
	if(dp[k][v]!=-1)return dp[k][v];
	long long take = d(k-1,v+m) + val(v);
	long long skip = d(k,v+1);
	return dp[k][v] = max(take,skip);
}

int main(){
	scanf("%d %d %d",&n,&m,&k);
	int c;
	cin >> c;
	p[0] = sum[0] = c;
	for(int i = 1; i < n; i++){
		cin >> c;
		p[i] = c;
		sum[i] = sum[i-1] + c;
	}
	for(int i = 0; i < 5010; i++){
		memset(&dp[i],-1,sizeof(dp[i]));
	}
	cout << d(k,0);
	return 0;
}