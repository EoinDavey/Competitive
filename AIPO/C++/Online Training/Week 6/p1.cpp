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


int c[100000][3];

int main(){
	string s;
	getline(cin,s);
	if(s[0]=='x') c[0][0]++;
	else if(s[0]=='y') c[0][1]++;
	else if(s[0]=='z') c[0][2]++;
	for(int i = 1; i < s.size(); i++){
		memcpy(c[i],c[i-1],sizeof(c[i-1]));
		if(s[i]=='x')c[i][0]++;
		else if(s[i]=='y')c[i][1]++;
		else if(s[i]=='z')c[i][2]++;
	}
	int m;
	scanf("%d",&m);
	int l,r;
	int sumX, sumY,sumZ,minC;
	for(int i = 0; i < m;i++){
		cin >> l >> r;
		l-=1;
		r-=1;
		sumX = c[r][0] - c[l-1][0];
		sumY = c[r][1] - c[l-1][1];
		sumZ = c[r][2] - c[l-1][2];
		//printf("l: %d, r: %d, i: %d, x: %d, y: %d, z: %d ",l,r,i,sumX,sumY,sumZ);
		//printf("%d %d\n",l+1,r+1);
		minC = min(sumX,sumY);
		minC = min(minC,sumZ);
		sumX-=minC;
		sumY-=minC;
		sumZ-=minC;
		if(sumX+sumY+sumZ > 2){
			cout << "NO" << endl;
		} else if(sumX < 2 && sumY < 2 && sumZ < 2){
			cout << "YES" << endl;
		} else if(r-l <= 1){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	
	return 0;
}