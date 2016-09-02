#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>

using namespace std;

unsigned long long int modPow = pow(10,9) + 7;

unsigned long long int fac(int n){
	unsigned long long int res = 1;
	for(int i = 2; i <= n; i++){
		res=(i * res);
	}
	return res;
}

void solve(int n, int k){
	unsigned long long int top = 1;
	for(int i = n-k+1; i <=n; i++){
		top=(top*i);
	}
	top = top;
	unsigned long long int bottom = fac(k);
	unsigned long long int result = (top/bottom) % modPow;
	cout << top << "/" << bottom << endl;
	cout<<result<<endl;
}

int main(){
	int t,n,k;
	scanf("%i",&t);
	for(int i = 0; i < t; i++){
		scanf("%i %i",&n,&k);
		solve(n,k);
	}
	return 0;
}