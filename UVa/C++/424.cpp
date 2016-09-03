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

int offset = (int) '0';

string add(string one, string two){
	string o;
	int max = (one.length() > two.length()) ? one.length():two.length();
	while(one.length() < max){
		one.insert(0,"0");
	}
	while(two.length() < max){
		two.insert(0,"0");
	}
	int sum = 0;
	int carry = 0;
	for(int i = max-1; i >=0; i--){
		sum = ((int)one[i])-offset + ((int) two[i])-offset + carry;
		carry = sum/10;
		o.insert(0,to_string(sum%10));
	}
	if(carry > 0){
		o.insert(0,to_string(carry));
	}
	return o;
}
int main(){
	string c;
	getline(cin,c);
	string f;
	while(getline(cin,f)){
		if(f=="0")break;
		c = add(c,f);
	}
	cout << c << endl;
	return 0;
}