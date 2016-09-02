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
#include <queue>
#include <stdint.h>
using namespace std;
int main(){
	string c;
	cin >> c;
	int l = 0;
	int fours, sevens;
	fours = sevens = 0;
	while(c[l]-'0' == 4 || c[l]-'0' == 7){
		l++;
	}
	for(int i = 0; i < l; i++){
		if(c[i]-'0' == 4){
			fours++;
		} else {
			sevens++;
		}
	}
	if(c.size()%2==0){
		//even
		if(c[l])
	} else {
		//odd
		for(int i = 0; i < (c.size()+1)/2 ; i++){
			cout << 4;
		}
		for(int i = ((c.size()+1)/2); i < c.size()+1; i++){
			cout << 7;
		}
		cout << endl;
	}
	cout << l << " " << fours << " " << sevens << endl;
	return 0;
}