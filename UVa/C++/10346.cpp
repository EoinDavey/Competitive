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
#include <stdint.h>
using namespace std;
int main(){
	long long n,k;
	while(scanf("%lld %lld",&n,&k)!=EOF){
		int count = 0;
		long long c=n*k;
		while(c>=k){
			long long r = c/k;
			count+=r;
			c = r + c%k;
		}
		cout << count << endl;
	}
	return 0;
}