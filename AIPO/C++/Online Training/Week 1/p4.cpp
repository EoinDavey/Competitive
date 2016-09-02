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
using namespace std;

int n,k;

int main(){
	int n,k;
	cin >> n >> k;
	char ca[] = {'A'};
	int offset = ca[0]-1;
	int stripe[n];
	for(int i = 0; i < n; i++){
		char c;
		scanf("%c",&c);
		if(c=='\n'){
			i--;
			continue;
		}
		int val = c-offset;
		stripe[i]=val;
	}
	int count = 0;
	if(k>2){
		for(int i = 0; i < n; i++){
			if(stripe[i]==stripe[i+1]){
				int f = 1;
				while(f == stripe[i+1] || f== stripe[i+2]){
					f++;
				}
				stripe[i+1]=f;
				count++;
			}
		}
	} else {
		int d=0;
		for(int i = 0; i<n; i++){
			if(stripe[i]==1 && (i&1)==0){
				d++;
			} else if(stripe[i]==2 && (i&1)==1){
				d++;
			}
		}
		count = (n-d<d) ? n-d:d;
		bool b=true;
		if(count==n-d){
			b=true;
		} else b = false;
		for(int i = 0; i < n; i++){
			if(b) stripe[i]=1;
			else stripe[i]=2;
			b=!b;
		}
	}
	cout << count << endl;
	for(int i = 0; i < n; i++){
		char c = stripe[i] + offset;
		cout << c;
	}
	cout << endl;
	return 0;
}