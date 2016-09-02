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
	uint32_t n;
	while(scanf("%u",&n), n!=0){
		uint32_t sqt = (uint32_t) sqrt(n);
		if(sqt*sqt == n){
			printf("yes\n");
		} else printf("no\n");
	}
	return 0;
}