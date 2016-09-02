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
	int q;
	scanf("%d",&q);
	string oldS,newS;
	string startList[1001];
	string curList[1001];
	int pos;
	int c = 0;
	bool found = false;
	for(int i = 0; i < q; i++){
		cin >> oldS >> newS;
		found = false;
		for(int j = 0; j < c && !found; j++){
			if(curList[j]==oldS){
				pos = j;
				found = true;
			}
		}
		if(!found){
			startList[c] = oldS;
			curList[c++] = newS;
		} else {
			curList[pos] = newS;
		}
	}
	cout << c << endl;
	for(int i = 0; i < c; i++){
		cout << startList[i] << " " << curList[i] << endl;
	}
	return 0;
}