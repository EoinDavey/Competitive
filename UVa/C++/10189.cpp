#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>
#include <stdlib.h>
using namespace std;

int main(){
	int n, m;
	long long int x=1;
	bool b = false;
	while(scanf("%d %d",&n,&m), n!=0 || m!=0){
		if(b) cout << endl;
		char board[n][m];
		for(int i = 0; i < n;i++){
			for(int j = 0; j < m; j++){
				char c;
				scanf("%c",&c);
				if(c=='\n'){
					j--;
					continue;
				}
				board[i][j] = c;
			}
		}
		for(int i = 0; i < n;i++){
			for(int j = 0; j < m; j++){
				if(board[i][j]=='*') continue;
				int count = 0;
				int up = i-1;
				int down = i+1;
				int left = j-1;
				int right = j+1;
				if(up >=0){
					if(right < sizeof(board[0])/sizeof(board[0][0])){
						if(board[up][right]=='*')count++;
					}
					if(board[up][j]=='*')count++;
					if(left >= 0){
						if(board[up][left]=='*')count++;
					}
				}
				if(right < sizeof(board[0])/sizeof(board[0][0])){
					if(board[i][right]=='*')count++;
				}
				if(left >= 0){
					if(board[i][left]=='*')count++;
				}
				if(down < sizeof(board)/sizeof(board[0])){
					if(right < sizeof(board[0])/sizeof(board[0][0])){
						if(board[down][right]=='*')count++;
					}
					if(board[down][j]=='*')count++;
					if(left >= 0){
						if(board[down][left]=='*')count++;
					}
				}
				char c[]={'0'};
				int offset = c[0];
				board[i][j] = count+offset;
			}
		}
		cout << "Field #" << x++ << ":" << endl;
		for(int i = 0; i < n;i++){
			for(int j = 0; j < m; j++){
				cout << board[i][j];
			}
			cout << endl;
		}b=true;
	}
	return 0;
}