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

vector<long long> list;

long long median(){
	sort(list.begin(),list.end());
	long long res=0;
	if(list.size() % 2==0){
		res = list[(list.size()/2)-1] + list[list.size()/2];
		res/=2;
	} else {
		res = list[(list.size()-1)/2];
	}
	return res;
}

int main(){
	long n;
	while(scanf("%lld",&n)!=EOF){
		list.push_back(n);
		cout << median() << endl;
	}
	return 0;
}