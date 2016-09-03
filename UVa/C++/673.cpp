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

int inc = 0;
string s;

bool parse(int b){
	char close = (s[b]=='(') ? ')':']';
	//cout << b << " " << close << endl;
	while(true){
		char c = s[++inc];
		if(inc>s.size()-1)return false;
		//cout << inc-1 << " " << c << endl;
		if(c=='('||c=='['){
			if(!parse(inc)){
				return false;
			}
		}
		if(c==']'||c==')'){
			if(c==close) return true;
			else return false;
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	getline(cin,s);
	for(int i = 0; i<n;i++){
		inc = 0;
		getline(cin,s);
		bool valid = true;
		while(inc<s.size() && valid){
			//printf("Starting parse at: %d, %c\n",inc,s[inc]);
			if(inc==s.size()-1){
				valid = false;
				continue;
			}
			if(s[inc]=='('||s[inc]=='['){
				if(!parse(inc)){
					valid = false;
				}
				inc++;
			} else {
				valid = false;
			}
		}
		if(i==173||i==174||i==175){
			//cout << s << ", " << valid << endl;
		}
		if(valid) cout << "Yes"<<endl;
		else cout << "No" << endl;
	}
	return 0;
}