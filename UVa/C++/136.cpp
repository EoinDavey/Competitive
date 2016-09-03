#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>
#include <stdlib.h>
#include <vector>
using namespace std;
int main(){
	long long int count[]={0,0,0};
	vector<long long int> digits;
	digits.push_back(1);
	while(digits.size() != 1500){
		long long int minV = INT_MAX;
		long long int val2 = 2*digits[count[0]];
		long long int val3 = 3*digits[count[1]];
		long long int val5 = 5*digits[count[2]];
		minV = (val2 < val3) ? val2:val3;
		minV = (minV < val5) ? minV:val5;
		digits.push_back(minV);
		if(val2==minV) count[0]++;
		if(val3==minV) count[1]++;
		if(val5==minV) count[2]++;
	}
	cout << "The 1500'th ugly number is " << digits.back() << "." << endl;
	return 0;
}