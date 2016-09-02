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
#include <queue>
#include <stdint.h>
using namespace std;
int main(){
	int h1, h2,a,b;
	int du,dv;
	scanf("%d %d",&h1,&h2);
	scanf("%d %d",&a,&b);
	du = a * 12;
	dv = b*12;
	h1 = h1 + a*8; // Day 1 from 2pm
	int count = 0;
	if(h1>h2){
		cout << count << endl;
		return 0;
	}
	if(du<dv){
		cout << -1 << endl;
		return 0;
	}
	h1-=dv;
	while(true){
		count ++;
		h1+=du;
		if(h1>h2){
			cout << count << endl;
			break;
		}
		h1-=dv;
	}
	return 0;
}