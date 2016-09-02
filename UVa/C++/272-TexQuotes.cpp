#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
int main(){
	string s;
	bool b=true;
	while(getline(cin,s)){
		for(int i = 0; i < s.length(); i++){
			if(s.at(i) == '"'){
				s.erase(i,1);
				if(b) s.insert(i,"``");
				else s.insert(i,"''");
				b= !b;
			}
		}
		cout << s << endl;
	}
	return 0;
}