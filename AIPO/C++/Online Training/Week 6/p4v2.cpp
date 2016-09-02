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
int N,Q;
int arr[200002];
int out[200002];
int w[200002];

int main(){
	//0 is long long long long intervals
	//1 is sum tree
	cin >> N >> Q;
	for(int i = 0; i <N;i++){
		cin >> arr[i];
	}
	sort(arr, arr+N);
	int li,ri;
	for(int q = 0; q < Q;q++){
		scanf("%d%d",&li,&ri);
		w[li]+=1;
		w[ri+1]-=1;
	}
	int r = 0;
	for(int i = 1; i <=N;i++){
		r+=w[i];
		out[i]=r;
	}
	sort(out+1,out+N+1);
	long long int sum = 0;
	for(int i = 1; i <= N;i++){
		sum+=(long long)arr[i-1]*(long long)out[i];
	}
	cout << sum << endl;
	return 0;
}