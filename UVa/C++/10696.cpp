#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>
#include <stdlib.h>
#include <vector>
#include <string.h>
using namespace std;


int main(){
	int n;
	while(cin>>n){
		int val;
		if(n==0) break;
		if(n>=101)val = n-10;
		else val = 91;
		cout << "f91(" << n << ") = " << val << endl;
	}
}