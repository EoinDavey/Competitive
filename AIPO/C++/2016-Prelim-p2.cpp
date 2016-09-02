#include <iostream>
#include <string>

using namespace std;

string str;

void readIn(){
	cin >> str;
}

void print(string s){
	cout << s;
}

int main(){
	readIn();
	bool valid = true;
	for(int i = 0; i < str.length()/2; i++){
		if(str[i] != str[str.length()-i-1]){
			valid = false;
			break;
		}
	}
	if(valid){
		print("true");
	} else print("false");
	return 0;
}