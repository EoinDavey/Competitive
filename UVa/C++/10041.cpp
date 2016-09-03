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
	int t,r;
	scanf("%d",&t);
	for(int i = 0; i < t; i++){
		scanf("%d",&r);
		int s[r];
		int mi = 30000;
		int mx = 0;
		int c;
		memset(s,0,sizeof(s));
		for(int j = 0; j < r; j++){
			scanf("%d",&c);
			s[j] = c;
			if(c<mi)mi=c;
			if(c>mx)mx=c;
		}
		int min = 15000000;
		int count = 0;
		for(int j = mi; j <= mx;j++){
			count = 0;
			for(int k = 0; k < r; k++){
				count+= abs(s[k]-j);
			}
			//cout << j << " " << count<<endl;
			if(count<min)min=count;
		}
		cout << min << endl;
	}
	return 0;
}