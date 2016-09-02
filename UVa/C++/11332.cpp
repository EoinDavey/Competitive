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

char c = '0';
int offset = (int) c;

int f(long i){
	string c = to_string(i);
	long tot = 0;
	for(int j = 0; j < c.length(); j++){
		tot+= ((long) c[j]);
		tot-=offset;
	}
	return (tot==i) ? tot:f(tot);
}
int main(){
	long long n;
	while(scanf("%lld",&n),n!=0){
		cout << f(n) << endl;;
	}
	return 0;
}