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
#include <queue>
#include <algorithm>
#include <stdint.h>
using namespace std;

struct edge{
	int v;
	int d;
};

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	bool visited[20000];
	memset(visited,false,sizeof(visited));
	if(n>=m){
		cout << n-m << endl;
	} else {
		queue<edge> q;
		edge e;
		e.v=n;
		e.d=0;
		q.push(e);
		int min = 50000;
		while(!q.empty()){
			edge c = q.front();
			q.pop();
			visited[c.v]=true;
			//cout << "proccing " << c.v << " at " << c.d << endl; 
			if(c.v==m){
				if(c.d<min)min=c.d;
				continue;
			}
			//double
			if(c.v<m){
				edge n;
				n.v = 2*c.v;
				n.d = c.d+1;
				if(!visited[n.v]){
					q.push(n);
				}
			}
			//sub
			if(c.v-1>0){
				edge n;
				n.v = c.v-1;
				n.d = c.d+1;
				if(!visited[n.v]){
					q.push(n);
				}
			}
		}
		cout << min << endl;
	}
	return 0;
}