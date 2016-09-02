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
int g[5][5];
int p[5];
int countf = 0;
int maxc = 0;

void dfs(int d, int c){
	if(c==31){
		countf++;
		int sum = g[p[0]][p[1]] + g[p[1]][p[0]] + g[p[2]][p[3]] + g[p[3]][p[2]];
		sum += g[p[1]][p[2]] + g[p[2]][p[1]] + g[p[3]][p[4]] + g[p[4]][p[3]];
		sum+= g[p[2]][p[3]] + g[p[3]][p[2]];
		sum+= g[p[3]][p[4]] + g[p[4]][p[3]];
		if(sum>maxc) maxc = sum;
		return;
	}
	for(int i = 0; i < 5; i++){
		if((c&(1<<i))==0){
			c = c|(1<<i);
			p[d] = i;
			dfs(d+1,c);
			c = c & ~(1<<i);
		}
	}
}

int main(){
	for(int i = 0; i<5; i++){
		for(int j = 0;j < 5; j++){
			cin >> g[i][j];
		}
	}
	//brute force
	dfs(0,0);
	cout << maxc << endl;;
	return 0;
}