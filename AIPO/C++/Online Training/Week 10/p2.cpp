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
char s[16];
int main(){
	cin >> n;
	cin >> s;
	vector<int> digits;
	int x;
	for(int i = 0; i < n; i++){
		x = s[i]-'0';
		if(x==0||x==1)continue;
		if(x==4){
			digits.push_back(2);
			digits.push_back(2);
			digits.push_back(3);
		} else if(x==6){
			digits.push_back(5);
			digits.push_back(3);
		}else if(x==8){
			digits.push_back(7);
			digits.push_back(2);
			digits.push_back(2);
			digits.push_back(2);
		}else if(x==9){
			digits.push_back(7);
			digits.push_back(3);
			digits.push_back(3);
			digits.push_back(2);
		} else {
			digits.push_back(x);
		}
	}
	sort(digits.begin(),digits.end());
	for(vector<int>::reverse_iterator i = digits.rbegin(); i!= digits.rend(); i++){
		cout << *i;
	}
	cout << endl;
	return 0;
}