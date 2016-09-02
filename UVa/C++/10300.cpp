#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int f;
		long long int tot = 0;
		cin >> f;
		for(int j = 0; j < f; j++){
			long long int size,no,en;
			scanf("%lld %lld %lld \n",&size, &no, &en);
			tot += size * en;
		}
		cout << tot << endl;
	}
	return 0;
}