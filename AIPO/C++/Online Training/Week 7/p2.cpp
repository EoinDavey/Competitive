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
int N,K,d;
long long memo[110][2];
long long modLim = pow(10,9) + 7;

long long dp(int n, int j){
	//cout << n << "," << j << endl;
	if(n==0&&j==1){
		return 1;
	}
	if(n<=0) return 0;
	if(memo[n][j] != -1) return memo[n][j];
	long long sum = 0;
	for(int i = 1; i <= n && i <= K; i++){
		if(i>=d){
			sum+=(dp(n-i,1) % modLim);
		} else {
			sum+=(dp(n-i,j) % modLim);
		}
	}
	return memo[n][j] = (sum % modLim);
}

int main(){
	scanf("%d %d %d",&N,&K,&d);
	for(int i = 0; i < 110; i++){
		memo[i][0] = memo[i][1] = -1;
	}
	cout << dp(N,0) % modLim << endl;
	return 0;
}