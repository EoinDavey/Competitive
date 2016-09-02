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
#include <stdint.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int l = 0;
	bool solved=false;
	for(int i = 1; l < n && !solved; i++){
		l+=i;
		int m = 0;
		for(int j = 1; m<n-l&&!solved;j++){
			m+=j;
			//printf("%d : %d\n",l,m);
			if(m+l==n){
				printf("YES\n");
				solved = true;
			}
		}
	}
	if(!solved)cout << "NO\n";
	return 0;
}