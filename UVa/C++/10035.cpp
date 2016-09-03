#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>
using namespace std;
int main(){
	long long int i,j;
	int carrys = 0;
	while(scanf("%lld %lld",&i,&j),(i!=0||j!=0)){
		string sI = to_string(i);
		string sJ = to_string(j);
		int maxLen = 0;
		if(sI.length() > sJ.length()){
			maxLen = sI.length();
			while(sJ.length() < maxLen){
				sJ.insert(0,1,'0');
			}
		} else {
			maxLen = sJ.length();
			while(sI.length() < maxLen){
				sI.insert(0,1,'0');
			}
		}
		string s = "0";
		int offset = s[0],carry,count;
		carry = count=0;
		for(int k = sI.length()-1; k >=0; k--){
			int vI = sI[k]-offset;
			int vJ = sJ[k]-offset;
			int sum = carry + vI + vJ;
			if(sum >=10){
				carry = sum/10;
				count++;
			} else {
				carry = 0;
			}
		}
		if(count == 0) cout << "No carry operation."<<endl;
		else if(count == 1) cout << "1 carry operation." << endl;
		else cout << count << " carry operations." << endl;
	}
	return 0;
}