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
long long int trees[2][200002];
long long int N,Q;
long long int arr[200002];

long long int LSOne(long long int S){
	return S & (-S);
}

void update(long long int l, long long int k, long long int v){
	for(;k<=N;k+=LSOne(k)){
		trees[l][k]+=v;
	}
}

long long int RSQ(long long int l, long long int k){
	long long int sum = 0;
	for(;k;k-=LSOne(k)){
		sum+=trees[l][k];
	}
	return sum;
}

int main(){
	//0 is long long intervals
	//1 is sum tree
	cin >> N >> Q;
	for(long long int i = 0; i <N;i++){
		cin >> arr[i];
	}
	sort(arr, arr+N);
	long long int l,r;
	vector<pair<long long int,long long int> > v;
	for(long long int q = 0; q < Q; q++){
		cin >> l >> r;
		v.push_back(pair<long long int,long long int>(l,r));
		update(0,l,1);
		update(0,r+1,-1);
	}
	pair<long long int,long long int> p[N];
	for(long long int i = 0; i < N; i++){
		p[i] = pair<long long int,long long int>(RSQ(0,i+1),i);
	}
	sort(p,p+N+1);
	for(long long int i = N-1; i >= 0; i--){
		update(1,p[i].second+1,arr[i]);
	}
	long long int sum = 0;
	for(vector<pair<long long int, long long int> >::iterator i = v.begin(); i!=v.end(); i++){
		sum+= RSQ(1,i->second) - RSQ(1, i->first - 1);
	}
	cout << sum << endl;
	return 0;
}