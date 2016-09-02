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
int main(){
	int o,e,n;
	o=1;
	e=0;
	cin >> n;
	int out[n][n];
	stack<int> odd;
	stack<int> even;
	for(int i = 1; i <= n*n; i++){
		if(i%2==0)even.push(i);
		else odd.push(i);
	}
	return 0;
}