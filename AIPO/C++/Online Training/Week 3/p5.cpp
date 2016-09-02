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
#include <set>

using namespace std;


int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	vector<vector<int> > adjList(n+1);
	int a,b;
	for(int i = 0; i < m;i++){
		scanf("%d %d",&a,&b);
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
	for(int i = 0; i <=n; i++){
		sort(adjList[i].begin(),adjList[i].end());
	}
	int c = 0;
	vector<vector<int> > sets;
	queue<int> q;
	set<int> s;
	int f;
	for(int i = 1; i <=n; i++){
		s.insert(i);
	}
	int i;
	int k;
	while(!s.empty()){
		i=*(s.begin());
		//cout << "Starting at "<< i << endl;
		s.erase(s.begin());
		/*for(set<int>::iterator j = s.begin(); j!=s.end(); j++){
			cout << *j << ",";
		}*/
		//cout << endl;
		sets.push_back(vector<int>());
		q.push(i);
		while(!q.empty()){
			f = q.front();
			q.pop();
			//cout << "start " << f << endl;
			sets[c].push_back(f);
			for(set<int>::iterator j = s.begin(); j!=s.end();){
				k=*j;
				j++;
				//cout << "Searching for " << k << endl;
				if(!binary_search(adjList[f].begin(),adjList[f].end(),k)){
					//cout << "Found " << k<<endl;
					q.push(k);
					s.erase(k);
				} //else cout << "Didn't find " << k<<endl;
			}
		}
		c++;
	}
	cout << c << endl;
	for(vector<vector<int> >::iterator i = sets.begin(); i!=sets.end(); i++){
		cout << i->size();
		for(vector<int>::iterator j = i->begin(); j!= i->end(); j++){
			cout << " " << *j;
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}