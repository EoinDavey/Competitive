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
int n,m;
bool cat[100002];
vector<int> adjList[100002];

struct edge{
	int c,v,p;
	edge(int ci, int vi,int pi){
		c = ci;
		v = vi;
		p = pi;
	}
};

int main(){
	scanf("%d %d",&n,&m);
	int c;
	for(int i = 1; i <= n; i++){
		scanf("%d",&c);
		cat[i] = c;
	}
	int x,y;
	for(int i = 1; i < n; i++){
		scanf("%d %d",&x,&y);
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}
	stack<edge> q;
	edge e(0,1,-1);
	q.push(e);
	int v,p;
	int count = 0;
	while(!q.empty()){
		e = q.top();q.pop();
		c = e.c;
		v = e.v;
		p = e.p;
		if(cat[v]){
			c++;
		}
		//printf("visitng %d, c: %d\n",v,c);
		if(c>m){
			//stop
			continue;
		}
		bool l = true;
		for(vector<int>::iterator i = adjList[v].begin(); i != adjList[v].end(); i++){
			if(*i==p) continue;
			l = false;
			if(cat[v]){
				q.push(edge(c,*i,v));
			} else {
				q.push(edge(0,*i,v));
			}
		}
		if(l){
			count++;
		}
	}
	cout << count << endl;
	return 0;
}