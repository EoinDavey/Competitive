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
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		uint64_t s,d;
		scanf("%llu %llu",&s,&d);
		if(s==0ULL&&d==0ULL){
			cout << "0 0" << endl;
			continue;
		}
		//try for x
		uint64_t x;
		bool stop = false;
		x = s + d;
		if((x&1ULL)==0ULL){
			x/= 2;
			if(s>x){
			uint64_t tY = s-x;
				if(x>0&&tY>0){
					uint64_t max = (tY > x) ? tY:x;
					uint64_t min = s-max;
					printf("%llu %llu\n",max,min);
					stop = true;
				}
			}
		}
		//try for y
		if(!stop){
			uint64_t y;
			y = s + d;
			if((y&1ULL)==0ULL){
				y/=2;
				if(s>y){
					uint64_t tX = s-y;
					if(x>0&&tX>0){
						uint64_t max = (tX > y) ? tX:y;
						uint64_t min = s-max;
						printf("%llu %llu\n",max,min);
						stop = true;
					}
				}
			}
		}
		if(!stop) cout << "impossible"<<endl;
	}
	return 0;
}