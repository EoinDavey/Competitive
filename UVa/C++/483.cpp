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
using namespace std;

string rev(string s){
	stringstream ss;
	for(int i = s.length()-1; i>=0;i--){
		ss << s[i];
	}
	return ss.str();
}

int main(){
	char c;
	stringstream word;
	while(scanf("%c",&c)==1){
		if(c==' '||c=='\n'||c=='\t'){
			cout << rev(word.str())<< c;
			word.str("");
		} else {
			word << c;
		}
	}
	cout << rev(word.str());
	return 0;
}