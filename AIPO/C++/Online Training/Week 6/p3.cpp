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
int trees[27][200002];
string s;
string o;
int K;

int LSOne(int s){
	return s&(-s);
}

int RSQ(int l,int v){
	int sum = 0;
	for(; v; v-=LSOne(v)){
		sum+=trees[l][v];
	}
	return sum;
}

int search(int l, int v, int low, int high){
	//printf("Searching for %d from %d to %d\n",v,low,high);
	int mid = (low+high)/2;
	if(RSQ(l,mid) > v){
		return search(l,v,low,mid-1);
	} else if(RSQ(l,mid) < v){
		return search(l,v,mid+1,high);
	} else {
		while(RSQ(l,mid) == v){
			mid--;
		}
		return mid+1;
	}
}


void update(int l,int k, int v){
	for(; k <= K*s.size();k+=LSOne(k)){
		trees[l][k]+=v;
	}
}


int main(){
	cin >> K;
	cin >> s;
	int pos = 0;
	for(int i = 1; i <= K * s.size();i++){
		int v = s[(i-1)%s.size()] - 'a' + 1;
		o+=s[(i-1)%s.size()];
		//cout << v << " ";
		//fenwick update
		update(v,i,1);
	}
	//cout << o << endl;
	int n;
	cin >> n;
	int p;
	char c;
	for(int i = 0; i < n;i++){
		cin >> p >> c;
		int v = c-'a' + 1;
		//printf("%dth occurence of %c: ",p,c);
		int pos = search(v, p, 0, K*s.size());
		o[pos-1] = ' ';
		update(v,pos,-1);
		//cout << o << endl;
		//cout << search(v, p, 0, K*s.size()) << endl;
	}
	for(int i = 0; i < o.size(); i++){
		if(o[i]!=' '){
			cout << o[i];
		}
	}
	cout << endl;
	return 0;
}