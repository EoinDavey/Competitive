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
#include <fstream>
using namespace std;
int main(){
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	
	int n;
	in>>n;
	int temp[n];
	for(int i = 0; i < n; i++){
		in >> temp[i];
	}
	
	int neg[n];
	memset(neg,0,sizeof(neg));
	int pos[n];
	memset(pos,0,sizeof(pos));
	if(temp[0]<0) neg[0]=1;
	for(int i = 1; i < n; i++){
		neg[i] = neg[i-1];
		if(temp[i]<0) neg[i]++;
	}
	if(temp[n-1]>0)pos[n-1] = 1;
	for(int i = n-2; i >=0; i--){
		pos[i] = pos[i+1];
		if(temp[i] > 0) pos[i]++;
	}
	int best = 100000000;
	for(int i = 0; i < n-1; i++){
		int c = (i+1-neg[i]) + (n-i-1 - pos[i+1]);
		if(c < best) best = c;
	}
	out << best << endl;
	in.close();
	out.close();
	return 0;
}