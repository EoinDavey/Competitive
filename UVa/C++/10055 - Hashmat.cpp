#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
int main(){
	long long int m,n;
	while(scanf("%ld %ld", &m, &n) != EOF){
		if(m>n){
			cout << m-n << endl;
		} else cout << n-m << endl;
	}
	return 0;
}