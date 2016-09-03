#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>
#include <stdlib.h>
#include <vector>
#include <string.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int t = 0; t < n; t++){
		int a,f;
		cin >> a >> f;
		for(int i = 0; i < f; i++){
			for(int j = 1; j <= a; j++){
				for(int k = 0; k < j; k++){
					cout << j;
				}
				cout << endl;
			}
			for(int j = a-1; j >=1 ; j--){
				for(int k = 0; k < j; k++){
					cout << j;
				}
				cout << endl;
			}
			if(t==n-1 && i == f-1){
			} else cout<< endl;
		}
	}
	return 0;
}