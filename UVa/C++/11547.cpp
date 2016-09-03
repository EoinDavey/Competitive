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
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	long long d;
	for(int i = 0; i < t; i++){
		scanf("%lld",&d);
		d*=63;
		d+=7492;
		d*=5;
		d-=498;
		string s = to_string(d);
		cout<< s[s.length()-2] << endl;
	}
	return 0;
}