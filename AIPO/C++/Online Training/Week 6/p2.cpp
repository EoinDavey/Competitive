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

int W[200000],H[200000];
int widthSum=0;
int maxH, max2H;

int main(){
	int n;
	cin >> n;
	maxH = max2H = 0;
	cin >> W[0] >> H[0];
	widthSum+=W[0];
	maxH = H[0];
	for(int i = 1; i < n;i++){
		cin >> W[i] >> H[i];
		widthSum+=W[i];
		if(H[i] > maxH){
			max2H = maxH;
			maxH = H[i];
		} else if(H[i]> max2H){
			max2H = H[i];
		}
	}
	int res;
	res = widthSum-W[0];
	if(H[0] == maxH){
		res*=max2H;
	} else res *= maxH;
	cout << res;
	for(int i = 1; i < n;i++){
		res = widthSum-W[i];
		if(H[i] == maxH){
			res*=max2H;
		} else res *= maxH;
		cout <<" "<< res;
	}
	return 0;
}