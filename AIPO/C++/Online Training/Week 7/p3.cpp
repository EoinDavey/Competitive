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

bool row[102];
int zeroes[102];
int main(){
	int n;
	scanf("%d",&n);
	scanf("%d",&row[0]);
	if(!row[0]){
		zeroes[0] = 1;
	}
	for(int i = 1; i < n;i++){
		scanf("%d",&row[i]);
		zeroes[i] = zeroes[i-1];
		if(!row[i]){
			zeroes[i]++;
		}
	}
	int max = 0;
	int val;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			if(i>0){
				val = (n-j-1-zeroes[n-1]+zeroes[j]) + (i-zeroes[i-1]);
				val+= zeroes[j] - zeroes[i-1];
			} else {
				val = (n-j-1-zeroes[n-1]+zeroes[j]) + zeroes[j];
			}
			if(val>max)max=val;
		}
	}
	cout << max << endl;
	return 0;
}