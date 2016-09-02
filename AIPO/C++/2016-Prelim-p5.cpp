#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(){
	int n;
	scanf("%i",&n);
	int price[n];
	for(int i = 0; i < n; i++){
		scanf("%i",&price[i]);
	}
	int maxDif=0;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			int pri = price[j] - price[i];
			if(pri > maxDif) maxDif = pri;
		}
	}
	cout<<maxDif<<endl;
	return 0;
}