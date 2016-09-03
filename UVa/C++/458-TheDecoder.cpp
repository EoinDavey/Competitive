#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
int main(){
	string s;
	while(getline(cin,s)){
		for(int i = 0; i < s.length(); i++){
			char c = s[i] - 7;
			cout << c;
		}
		cout << endl;
	}
	return 0;
}