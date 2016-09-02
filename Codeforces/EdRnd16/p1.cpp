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
	int c,d;
	scanf("%c%d",&c,&d);
	c = ((char) c) - 'a' + 1;
	int out = 8;
	if((c == 1 || c == 8)&&(d==1||d==8)){
		out = 3;
	} else if(c==1||c==8||d==1||d==8){
		out = 5;
	}
	cout << out << endl;
	return 0;
}