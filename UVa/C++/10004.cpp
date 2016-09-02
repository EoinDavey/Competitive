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
using namespace std;

vector<vector<int>> adjList;

struct edge{
	int colour;
	int v;
};

int main(){
	int t;
	while(cin>>t){
		if(t==0)break;
		adjList=vector<vector<int>>(t,vector<int>());
		int l;
		cin >> l;
		int colours[t];
		memset(colours,-1,sizeof(colours));
		for(int i = 0; i < l; i++){
			int m,n;
			cin >> m >> n;
			adjList[m].push_back(n);
			adjList[n].push_back(m);
		}
		stack<edge> s;
		edge start;
		start.colour = -1;
		start.v = 1;
		s.push(start);
		bool b = false;
		while(!s.empty()){
			edge c = s.top();
			s.pop();
			if(colours[c.v]!=-1){
				if(colours[c.v] == c.colour){
					b = true;
					break;
				} else continue;
			}
			int newC;
			if(c.colour == 1) newC=0;
			else newC = 1;
			colours[c.v] = newC;
			for(vector<int>::iterator i = adjList[c.v].begin(); i!= adjList[c.v].end(); i++){
				edge newE;
				newE.colour = newC;
				newE.v = *i;
				s.push(newE);
			}
		}
		if(b) cout << "NOT BICOLORABLE." << endl;
		else cout << "BICOLORABLE." << endl;
	}
	return 0;
}