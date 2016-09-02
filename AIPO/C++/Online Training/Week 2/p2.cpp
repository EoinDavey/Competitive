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
	int n,T;
	scanf("%d",&n);
	int times[n];
	for(int i = 0; i < n;i++){
		scanf("%d",&times[i]);
	}
	scanf("%d",&T);
	sort(times, times + n);
	int max = 0;
	for(int i = 0; i < n; i++){
		int lim = times[i]+T;
		int count = 0;
		for(int j = i;j<n; j++){
			if(times[j] > lim) break;
			else count ++;
		}
		if(count > max) max = count;
	}
	printf("%d\n",max);
	return 0;
}