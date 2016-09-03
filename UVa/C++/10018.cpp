#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>
#include <stdlib.h>
using namespace std;
long long int reverse(long long int n){
	long long int out = 0;
	string s = to_string(n);
	stringstream ss;
	for(int i = s.length()-1;i>=0;i--){
		ss << s[i];
	}
	return stoll(ss.str());
}

bool isPalindrome(long long int n){
	if(n==reverse(n))return true;
	else return false;
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n;i++){
		long long int in;
		cin >> in;
		int count = 0;
		do{
			count++;
			in=in + reverse(in);
		}while(!isPalindrome(in));
		cout << count << " " << in << endl;
	}
	return 0;
}