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

char board[505][505];
int ho[505][505],v[505][505];

int check(int r1,int c1,int r2,int c2){
	int count = 0;
	count += v[r2][c2] - v[r1][c2];
	if(c1 > 0){
		count -= v[r2][c1-1];
		count += v[r1][c1-1];
	}
	//cout << "v : " << count;
	count += ho[r2][c2] - ho[r2][c1];
	if(r1 > 0){
		count -= ho[r1-1][c2];
		count += ho[r1-1][c1];
	}
	//cout << " h: ";
	cout << count << endl;
}

int main(){
	int h,w;
	scanf("%d %d",&h,&w);
	char c;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			scanf("%c",&c);
			if(c=='\n'){
				j--;
				continue;
			}
			board[i][j] = c;
			if(c=='.'){
				if(i-1>=0){
					if(board[i-1][j]=='.'){
						v[i][j]=1;
					}
				}
				if(j-1>=0){
					if(board[i][j-1]=='.'){
						ho[i][j]=1;
					}
				}
			}
			if(i-1>=0){
				v[i][j]+=v[i-1][j];
				ho[i][j]+=ho[i-1][j];
			}
			if(j-1>=0){
				v[i][j]+=v[i][j-1];
				ho[i][j]+=ho[i][j-1];
			}
			if(i-1>=0 && j-1 >= 0){
				v[i][j] -= v[i-1][j-1];
				ho[i][j] -= ho[i-1][j-1];
			}
		}
	}
	int q;
	scanf("%d",&q);
	int r1,c1,r2,c2;
	for(int i = 0; i < q;i++){
		scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
		check(r1-1,c1-1,r2-1,c2-1);
	}
	return 0;
}