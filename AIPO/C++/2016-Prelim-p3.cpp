#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
	int i;
	scanf("%i",&i);
	stringstream ss;
	while(i!=1){
		ss<<i << " ";
		if(i%2==0) i = i/2;
		else i = 3*i + 1;
	}
	ss << "1";
	cout << ss.str();
	return 0;
}