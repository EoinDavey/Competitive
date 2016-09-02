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
int main(){
	string in;
	int offset = (int) '0';
	while(getline(cin,in),in!="0"){
		uint32_t total = 0;
		for(int i = 0; i < in.size();i++){
			int pw = in.size()-i;
			total += (pow(2,pw)-1) * (((int)in[i])-offset);
		}
		cout << total << endl;
	}
	return 0;
}