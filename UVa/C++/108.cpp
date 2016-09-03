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
	int n;
	while(cin >> n){
		int board[n][n];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%d",&board[i][j]);
				if(i>0) board[i][j] += board[i-1][j];
				if(j>0) board[i][j] += board[i][j-1];
				if(i>0 && j>0) board[i][j] -= board[i-1][j-1];
			}
		}
		int max = -127*100*100;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n;j++){
				for(int k = i; k < n;k++){
					for(int l = j; l < n; l++){
						int size = board[k][l];
						if(i > 0){
							size -= board[i-1][l];
						}
						if(j > 0){
							size -= board[k][j-1];
						}
						if(i>0&&j>0){
							size += board[i-1][j-1];
						}
						if(size>max)max=size;
					}
				}
			}
		}
		cout << max << endl;
	}
	return 0;
}