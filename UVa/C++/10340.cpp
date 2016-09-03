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
	string s,t;
	while(cin >> s >> t){
		int f[t.length()];
		memset(f,-1,sizeof(f));
		if(s[0]==t[0])f[0]=0;
		for(int i = 1; i < t.length(); i++){
			if(t[i]==s[f[i-1]+1]){
				f[i]=f[i-1]+1;
			} else {
				f[i]=f[i-1];
			}
		}
		if(f[t.length()-1]==s.length()-1) cout << "Yes"<<endl;
		else cout << "No" << endl;
	}
	return 0;
}