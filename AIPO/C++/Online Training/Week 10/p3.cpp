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
bool isPrime(int n){
	int sq = sqrt(n);
	bool p = true;
	for(int i = 2; i <= sq; i++){
		if(n%i == 0){
			p = false;
			break;
		}
	}
	return p;
}
int main(){
	bool prime[301];
	memset(prime,true,sizeof(prime));
	prime[1] = false;
	for(int i = 2; i <= 300; i++){
		if(prime[i]){
			for(int j = 2; i*j <= 300; j++){
				prime[i*j] = false;
			}
		}
	}
	int n,c;
	cin >> n;
	c=n;
	if(isPrime(n)){
		cout << 1 << endl;
		cout << n << endl;
		return 0;
	}
	while(true){
		//test if prime
		if(isPrime(c)){
			n-=c;
			if(n==2){
				cout << 2 << endl;
				cout << 2 << " " << c << endl;
				break;
			}
			for(int i = 2; i < n; i++){
				if(prime[i] && prime[n-i]){
					cout << 3 << endl;
					cout << c << " " << i << " " << n-i << endl;
					break;
				}
			}
			break;
		}
		c--;
	}
	return 0;
}