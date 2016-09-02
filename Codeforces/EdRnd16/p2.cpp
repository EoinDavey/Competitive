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
	int N;
	cin >> N;
	int arr[N];
	int sum = 0;
	for(int i =0; i < N; i++){
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	sort(arr, arr+N);
	if(N%2==0){
		cout << arr[N/2 - 1] << endl;
	} else {
		cout << arr[N/2] << endl;
	}
	return 0;
}