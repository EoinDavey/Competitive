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
	int n;
	while(scanf("%d",&n),n>=0){
		uint64_t result=0;
		result += n;
		result *= ((uint64_t)n+1);
		result/=2;
		result+=1;
		printf("%llu\n",result);
	}
	return 0;
}