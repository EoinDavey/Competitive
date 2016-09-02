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
	int p[n+1],rank[n+1];
	int f = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d",&f);
		if(f==-1){
			p[i]=i;
		} else {
			p[i]=f;
		}
	}
	for(int i = 1; i <= n; i++){
		//get rank
		int c = i;
		int count = 1;
		while(p[c]!=c){
			c=p[c];
			count++;
		}
		rank[i]=count;
		//cout << "rank " << i << "; " << count << endl;
	}
	int mx = 0;
	for(int i = 1; i <= n;i++){
		if(rank[i]>mx)mx=rank[i];
	}
	cout << mx << endl;
	return 0;
}