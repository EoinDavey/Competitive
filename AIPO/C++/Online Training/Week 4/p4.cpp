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
	int n, m;
	scanf("%d %d", &n, &m);
	int a,b;
	bool grid[n+1][n+1];
	int count[n+1];
	memset(count,0,sizeof(count));
	for(int i = 0; i <=n; i++){
		memset(grid[i],false,sizeof(grid[i]));
	}
	for(int i = 0; i <m ;i ++){
		scanf("%d %d", &a,&b);
		grid[a][b] = grid[b][a] = true;
		count[a]++;
		count[b]++;
	}
	int c = 0;
	bool changed = true;
	while(changed){
		c++;
		changed = false;
		vector<int> group;
		for(int i = 1; i <=n; i++){
			if(count[i]==1){
				changed = true;
				group.push_back(i);
			}
		}
		for(vector<int>::iterator i = group.begin(); i!= group.end(); i++){
			for(int j = 1; j <= n; j++){
				if(grid[*i][j]){
					grid[*i][j] = false;
					count[j]--;
					count[*i]--;
				}
			}
		}
	}
	cout << c-1 << endl;
	return 0;
}