#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int l;
		cin >> l;
		int train[l];
		for(int k = 0; k < l;k++){
			cin >> train[k];
		}
		bool solved = false;
		int count = 0;
		while(!solved){
			bool changed = false;
			for(int k = 0; k < l-1; k++){
				if(train[k] > train[k+1]){
					changed = true;
					int temp = train[k];
					train[k] = train[k+1];
					train[k+1]=temp;
					count++;
				}
			}
			if(!changed) solved = true;
		}
		cout << "Optimal train swapping takes "<< count << " swaps." << endl;
	}
	return 0;
}