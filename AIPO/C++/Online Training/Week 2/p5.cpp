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
#include <queue>
using namespace std;

const int M = 5e4 +10 , K =510;
long long dist[M][K];
int pa[M];
vector<vector<int> > adjList;

void dfs(int p,int a){
	pa[a] = p;
	//dist[a][0]=1LL;
	int n = 0;
	for(vector<int>::iterator i = adjList[a].begin(); i!=adjList[a].end();i++){
		if(*i==p) continue;
		dfs(a,*i);
		for(int j = 0; j < K; j++){
			dist[a][j+1] += dist[*i][j];
		}
		n++;
	}
	dist[a][1]=n;
}

long long calc(int u, int k){
	long long total = 0;
	int c = u;
	int prev = 0;
	total+=(long long)dist[u][k];
	for(int i = 1; i <= k && c!=1; i++){
		prev = c;
		c=pa[c];
		if(k-i==0){
			total+=1LL;
		} else {
			total+=(long long) dist[c][k-i]- (long long) dist[prev][k-i-1];
		}
	}
	return total;
}

int main(){
	int n, k;
	scanf("%d %d",&n,&k);
	adjList = vector<vector<int> >(n+1);
	int a,b;
	for(int i = 0; i < M; i++){
		memset(&dist[i],0,sizeof(dist[i]));
	}
	for(int i = 0; i < n-1; i++){
		scanf("%d %d",&a,&b);
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
	dfs(1,1);
	long long count = 0;
	for(int i = 1; i <=n;i++){
		dist[i][0]=1;
	}
	for(int i = 1; i <=n;i++){
		long long c= calc(i,k);
		count+=c;
		//cout << i << "," << k << " = " << c << endl;
	}
	count /=2;
	cout << count << endl;
	/*for(int i = 0; i <= n; i++){
		cout << i << " ";
	}
	cout << endl;
	for(int i = 0; i <= n; i++){
		cout << pa[i] << " ";
	}
	cout << endl;
	for(int i = 1; i <= n; i++){
		cout << i << " ";
		for(int j = 0; j < K; j++){
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}*/
	return 0;
}