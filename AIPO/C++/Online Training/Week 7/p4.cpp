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
#include <map>
using namespace std;
int N;
map<string, vector<string> > adjList;

struct edge{
	string v;
	int d;
	edge(string vi, int di){
		v = vi;
		d = di;
	}
};

int main(){
	scanf("%d",&N);
	string a, f, b;
	for(int i = 0; i < N; i++){
		cin >> a >> f >> b;
		transform(a.begin(),a.end(), a.begin(), ::tolower);
		transform(b.begin(),b.end(), b.begin(), ::tolower);
		adjList[b].push_back(a);
	}
	queue<edge> q;
	edge e("polycarp",1);
	q.push(e);
	string v;
	int d;
	int maxD = 0;
	while(!q.empty()){
		e = q.front(); q.pop();
		v = e.v;
		d = e.d;
		if(d>maxD)maxD=d;
		for(vector<string>::iterator i = adjList[v].begin(); i!=adjList[v].end();i++){
			q.push(edge(*i,d+1));
		}
	}
	cout << maxD << endl;
	return 0;
}