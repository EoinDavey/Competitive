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
	while(cin >> N){
		int arr[N];
		for(int i = 0; i < N;i++){
			cin >> arr[i];
		}
		int moves = 0;
		bool changed = false;
		do{
			changed = false;
			for(int i = 0; i < N-1; i++){
				if(arr[i] > arr[i+1]){
					int t = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = t;
					changed = true;
					moves++;
				}
			}
		}while(changed);
		printf("Minimum exchange operations : %d\n",moves);
	}
	return 0;
}