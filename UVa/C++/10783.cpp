#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>
using namespace std;
int main(){
	int T;
	cin >> T;
	int a,b,count;
	for(int i = 1; i <= T; i++){
		cin >> a >> b;
		count = 0;
		if(a%2==0){
			a=a+1;
		}
		for(int j = a; j <=b; j+=2){
			count+=j;
		}
		cout << "Case " << i << ": " << count << endl;
	}
	return 0;
}