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

struct edge{
	bool l;
	int u;
	edge(bool li, int ui){
		l=li;
		u=ui;
	}
};

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	bool grid[n+1][m+1];
	int l;
	int ln;
	for(int i = 0;i <= n; i ++){
		memset(grid[i],false,sizeof(grid[i]));
	}
	bool empty = true;
	for(int i = 1; i <=n;i++){
		cin >> ln;
		for(int j = 0; j < ln; j++){
			cin >> l;
			grid[i][l] = true;
			empty = false;
		}
	}
	bool visitedE[n+1];
	bool visitedL[m+1];
	memset(visitedE,false,sizeof(visitedE));
	memset(visitedL,false,sizeof(visitedL));
	int count = 0;
	for(int i = 1; i <=n; i++){
		if(visitedE[i])continue;
		count++;
		queue<edge> q;
		q.push(edge(false,i));
		while(!q.empty()){
			edge c = q.front();
			q.pop();
			int u = c.u;
			bool l = c.l;
			if(l){
				if(visitedL[u]) continue;
				visitedL[u] = true;
				for(int j = 1; j <= n; j++){
					if(grid[j][u] && !visitedE[j]){
						q.push(edge(false,j));
					}
				}
			} else {
				if(visitedE[u]) continue;
				visitedE[u] = true;
				for(int j = 1; j <=m; j++){
					if(grid[u][j] && !visitedL[j]){
						q.push(edge(true,j));
					}
				}
			}
		}
	}
	if(empty) cout << n << endl;
	else cout << count - 1 << endl;
	return 0;
}