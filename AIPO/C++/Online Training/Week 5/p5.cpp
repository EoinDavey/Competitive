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
	int a,b,d;
	edge(int ai,int bi, int di){
		a=ai;b=bi;d=di;
	}
};

int n,k;
int p[3003];
bool vis[3003][3003];
int hundreds[3003];
int ps[3003];
int main(){
	int count = 0;
	scanf("%d %d",&n,&k);
	for(int i = 0; i < n; i++){
		scanf("%d",&p[i]);
	}
	queue<edge> q;
	q.push(edge(0,1,0));
	int a,b,d;
	if(p[n-1] == 100) hundreds[n-1] = 1;
	if(p[n-1] > 0) ps[n-1] = 1;
	for(int i = n-2; i >= 0; i--){
		hundreds[i] = hundreds[i+1];
		if(p[i]==100) hundreds[i]++;
		ps[i] = ps[i+1];
		if(p[i] > 0) ps[i]++;
	}
	while(!q.empty()){
		edge e = q.front(); q.pop();
		a = e.a;
		b = e.b;
		d = e.d;
		if(d>k) continue;
		if(vis[a][b]) continue;
		vis[a][b] = true;
		count ++;
		if(a>=n||b>=n)continue;
		//a dies
		if(ps[b] > 0 && p[a]!=100){
			if(!vis[a+1][b+1]){
				q.push(edge(b,b+1,d+1));
			}
		}
		//b dies
		if(p[a]>0 && hundreds[b]==0){
			if(!vis[a][b+1]){
				q.push(edge(a,b+1,d+1));
			}
		}
		//both die
		if(p[a]>0 && ps[b] > 0){
			if(!vis[a+2][b+2]){
				q.push(edge(b+1,b+2,d+1));
			}
		}
	}
	cout << count << endl;
	return 0;
}