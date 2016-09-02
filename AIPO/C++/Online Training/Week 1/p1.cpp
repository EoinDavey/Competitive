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
#include <stdint.h>
using namespace std;
int main(){
	uint64_t a,b;
	cin >> a >> b;
	uint64_t c,w;
	c=w=0ULL;
	int count = 0;
	uint64_t max = 0;
	for(int i = 0; i < 64; i++){
		w=c;
		for(int k =0; k < i; k++){
			w=w|(1ULL<<k);
		}
		w=w&~(1ULL<<i);
		for(int k = i+1; k < 64; k++){
			w=w|(1ULL<<k);
			if(w >= a && w <= b){
				count++;
			}
			if(w>max)max=w;
		}
	}
	cout << count << endl;
	return 0;
}