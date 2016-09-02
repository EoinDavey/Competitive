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


int n,m;

int opCount = 0;

int board[510][510];
bool vis[510][510];

bool printActive = false;

stringstream res;

void dfs(bool r,int i,int j){
	//cout << "visiting " << i << "," << j << "; pi: " << pi << " pj: " << pj<< endl;
	vis[i][j]=true;
	//down
	if(i+1 <= n){
		if(board[i+1][j]==1 && !vis[i+1][j]){	
			dfs(true,i+1,j);
		}
	}
	//up
	if(i-1>=1){
		if(board[i-1][j]==1 && !vis[i-1][j]){
			dfs(true,i-1,j);
		}
	}
	//left
	if(j+1 <= m){
		//res << "trying"<<endl;
		if(board[i][j+1]==1&& !vis[i][j+1]){
			dfs(true,i,j+1);
		}
	}
	//right
	if(j-1>=1){
		if(board[i][j-1]==1&& !vis[i][j-1]){	
			dfs(true,i,j-1);
		}
	}
	if(board[i][j]==1 && r){
		//destroy blue
		if(!printActive){
			res << "D " << i << " " << j << endl;
			res << "R " << i << " " << j << endl;
		}
		opCount += 2;
		board[i][j]=2;
	}
}

int main(){
	scanf("%d %d",&n,&m);
	// -1 black hole
	// 0 empty
	//1 is blue
	//2 is red
	char c;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m;j++){
			cin >> c;
			if(c=='#')board[i][j]=-1;
		}
	}
	//fill with blue
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m;j++){
			if(board[i][j]==0){
				opCount ++;
				res << "B " << i << " " << j << endl;
				board[i][j]=1;
			}
		}
	}
	//find a source
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <=m; j++){
			if(board[i][j]==1){
				//res << "Starting at " << i << ", " << j << endl;
				//down
				if(i+1 <= n){
					if(board[i+1][j]==1){
						vis[i+1][j]==true;
						dfs(false,i+1,j);
					}
				}
				//up
				if(i-1>=1){
					if(board[i-1][j]==1){
						vis[i-1][j]=true;
						dfs(false,i-1,j);
					}
				}
				//left
				if(j+1 <= m){
					if(board[i][j+1]==1){
						vis[i][j+1] = true;
						dfs(false,i,j+1);
					}
				}
				//right
				if(j-1>=1){
					if(board[i][j-1]==1){	
						vis[i][j+1] = true;
						dfs(false,i,j-1);
					}
				}
			}
		}
	}
	cout << opCount << endl;
	cout << res.str();
	return 0;
}