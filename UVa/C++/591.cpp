#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>
#include <stdlib.h>
#include <vector>
using namespace std;
int main(){
	long long int n,count;
	count = 0;
	while(cin>>n){
		if(n==0) break;
		int stacks[n];
		int total,target,gap;
		total = target=gap=0;
		for(int i = 0; i < n; i++){
			int v;
			scanf("%d",&v);
			stacks[i] = v;
			total+=v;
		}
		target = total/n;
		for(int i = 0; i < n; i++){
			gap += abs(stacks[i]-target);
		}
		cout << "Set #" << ++count << endl;
		cout << "The minimum number of moves is " << gap/2 << "." << endl << endl;
	}
	return 0;
}