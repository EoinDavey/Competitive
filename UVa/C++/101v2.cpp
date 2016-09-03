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
using namespace std;

vector<int>p;
vector<int>r;
int n;

int findSet(int i){
	return (p[i]==i) ? i:findSet(p[i]);
}

bool sameSet(int i, int j){
	return findSet(i)==findSet(j);
}

void moveOnto(int a, int b){
	for(int i = 0; i < n; i++){
		if(sameSet()
	}
}

int main(){
	scanf("%d",&n);
	p.assign(n,0);
	r.assign(n,0);
	for(int i = 0; i < n; i++){
		p[i]=i;
	}
	char mov[5],com[5];
	int a,b;
	while(true){
		scanf("%s",mov);
		if(strcmp(mov,"quit")==0)break;
		scanf("%d %s %d",&a,com,&b);
	}
	return 0;
}