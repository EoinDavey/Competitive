#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>
using namespace std;
int main(){
	int count = 0;
	string s = "AZaz";
	int A = s[0];
	int Z = s[1];
	int a = s[2];
	int z = s[3];
	while(getline(cin,s)){
		count = 0;
		bool word = false;
		int val;
		for(int i = 0; i < s.length(); i++){
			val = s[i];
			if((val >= A && val <= Z)||(val>=a && val <=z)){
				if(!word) word=!word;
			} else {
				if(word){
					count++;
					word=!word;
				}
			}
		}
		if(word) count++;
		cout << count << endl;
	}
	return 0;
}