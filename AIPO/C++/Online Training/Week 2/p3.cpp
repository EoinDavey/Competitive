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
	string s;
	cin >> s;
	int max = 0;
	for(int i = 0; i < s.length();i++){
		int count = 1;
		int inc = 1;
		for(int j = i+1; j < s.length(); j++, inc++){
			if(s[i]==s[j]){
				if(inc&1){
					count++;
					inc=0;
				}
			}
		}
		if(count > max) max = count;
	}
	cout << max << endl;
	return 0;
}