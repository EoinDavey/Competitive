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
int n;
bool primes[1000001];
vector<int> primeVector;
int main(){
	//sieve
	memset(primes,true,sizeof(primes));
	primes[1] = 0;
	for(int i = 2; i <= 1000000; i++){
		if(primes[i]){
			primeVector.push_back(i);
			for(int j = 2; i*j <= 1000000; j++){
				primes[i*j] = false;
			}
		}
	}
	cin >> n;
	long long int x,sq;
	for(int i = 0; i < n;i++){
		cin >> x;
		sq = sqrt(x);
		if(sq*sq == x){
			if(primes[sq]){
				cout << "YES" << endl;
			} else cout << "NO" << endl;
		} else cout << "NO" << endl;
	}
	return 0;
}