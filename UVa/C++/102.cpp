#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>
using namespace std;
int main(){
	int bins[3][3];
	string s;
	string ans;
	int count,min;
	while(getline(cin,s)){
		stringstream ss;
		min = INT_MAX;
		ss << s;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				ss >> bins[i][j];
			}
		}
		//BCG
		count = bins[0][1] + bins[0][2] + bins[1][0] + bins[1][1] + bins[2][0] + bins[2][2];
		if(count < min){
			min = count;
			ans = "BCG";
		}
		//BGC
		count = bins[0][1] + bins[0][2] + bins[1][0] + bins[1][2] + bins[2][0] + bins[2][1];
		if(count < min){
			min = count;
			ans = "BGC";
		}
		//CBG
		count = bins[0][0] + bins[0][1] + bins[1][1] + bins[1][2] + bins[2][0] + bins[2][2];
		if(count < min){
			min = count;
			ans = "CBG";
		}
		//CGB
		count = bins[0][0] + bins[0][1] + bins[1][0] + bins[1][2] + bins[2][1] + bins[2][2];
		if(count < min){
			min = count;
			ans = "CGB";
		}
		//GBC
		count = bins[0][0] + bins[0][2] + bins[1][1] + bins[1][2] + bins[2][0] + bins[2][1];
		if(count < min){
			min = count;
			ans = "GBC";
		}
		//GCB
		count = bins[0][0] + bins[0][2] + bins[1][0] + bins[1][1] + bins[2][1] + bins[2][2];
		if(count < min){
			min = count;
			ans = "GCB";
		}
		cout << ans << " " << min << endl;
	}
	return 0;
}