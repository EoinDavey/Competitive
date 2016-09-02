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
	int v;
	int c;
};

int main(){
	int n, m; 
	scanf("%d %d",&n,&m);
	vector<edge> adjList[n+1];
	for(int i = 0; i < m; i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		edge e;
		e.c=c;
		e.v = b;
		adjList[a].push_back(e);
		e.v=a;
		adjList[b].push_back(e);
	}
	int a,b,q;
	scanf("%d",&q);
	for(int i = 0; i < q; i++){
		scanf("%d %d",&a,&b);
		int count = 0;
		//try each colour
		for(int j = 1; j <= m; j++){
			int colour = j;
			bool visited[n+1];
			memset(visited,false,sizeof(visited));
			//bfs
			queue<int> q;
			q.push(a);
			while(!q.empty()){
				int u = q.front();
				q.pop();
				visited[u] = true;
				if(u==b){
					count++;
					break;
				}
				for(vector<edge>::iterator k = adjList[u].begin(); k!=adjList[u].end();k++){
					if(k->c == colour && !visited[k->v]){
						q.push(k->v);
					}
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}