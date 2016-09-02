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
	int n;
	scanf("%d",&n);
	int pe[n];
	for(int i = 0; i < n;i++){
		scanf("%d",&pe[i]);
	}
	bool mat[n][n];
	char c;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%c",&c);
			if(c=='\n'){
				j--;
				continue;
			}
			if(c=='0')mat[i][j] = false;
			else mat[i][j] = true;
		}
	}
	bool visited[n];
	memset(visited,false,sizeof(visited));
	for(int i = 0; i < n; i++){
		vector<int> vi;
		queue<int> q;
		q.push(i);
		while(!q.empty()){
			int c = q.front();
			q.pop();
			if(visited[c])continue;
			vi.push_back(c);
			visited[c] = true;
			for(int j = 0; j < n;j++){
				if(mat[c][j] && !visited[j]){
					q.push(j);
				}
			}
		}
		sort(vi.begin(),vi.end());
		/*cout << "set at " << i << endl;
		for(vector<int>::iterator j = vi.begin(); j!=vi.end(); j++){
			cout << *j << " ";
		}*/
		//cout << endl;
		bool changed = true;
		while(changed){
			changed = false;
			for(int j = 0; j < vi.size();j++){
				for(int k = j+1; k < vi.size(); k++){
					int p = vi[j];
					int q = vi[k];
					if(pe[p] > pe[q]){
						//cout << "swapping " << p << " , " << q << endl;
						int t = pe[p];
						pe[p] = pe[q];
						pe[q] = t;
						changed = true;
					}
				}
			}
		}
	}
	cout << pe[0];
	for(int i = 1; i < n; i ++){
		cout << " " << pe[i];
	}
	cout << endl;
	return 0;
}