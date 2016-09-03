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
	long long int B,P,M;
	while(cin >> B >> P >> M){
		if(M==1||B==0){
			cout << 0 << endl;
			continue;
		}
		if(P==0){
			cout << 1%M << endl;
			continue;
		}
		if(P==1){
			cout << B%M << endl;
			continue;
		}
		int res = 1;
		int base = B%M;
		while(P>0LL){
			if(P%2LL==1LL){
				res = (res*base) % M;
			}
			P = (P >> 1LL);
			base = (base * base) % M;
		}
		cout << res << endl;
	}
	return 0;
}