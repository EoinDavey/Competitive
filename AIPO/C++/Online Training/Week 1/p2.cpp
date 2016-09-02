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
int main(){
	int n;
	cin >> n;
	char board[n][n];
	vector<pair<int,int> > v;
	vector<pair<int,int> >moves;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n;j++){
			char c;
			scanf("%c",&c);
			if(c=='\n'){
				j--;
				continue;
			}
			if(c=='o'){
				pair<int,int> p;
				p.first = i;
				p.second = j;
				v.push_back(p);
			}
			board[i][j] = c;
		}
	}
	
	for(int i = -1*n+1; i < n; i++){
		for(int j = -1*n +1; j < n; j++){
			//dx = i
			//dy = j
			//cout << "dx: " << i << " dy:" << j << endl;
			bool valid = true;
			for(vector<pair<int, int > >::iterator k = v.begin(); k != v.end(); k++){
				int x = k->first + i;
				int y = k->second + j;
				//cout << "x: " << x << "; y: " << y;
				if(x>=0 && x<n && y>=0 && y<n){
					if(board[x][y]=='.'){
						valid = false;
						//cout << endl;
						break;
					}
				}
				//cout << " Valid" << endl;
			}
			if(valid){
				//cout << "i:" << i << "; j:" << j<<endl;
				pair<int,int> p;
				p.first=i;
				p.second=j;
				moves.push_back(p);
			}
		}
	}
	
	bool stop = false;
	char board2[n][n];
	for(int i = 0; i < n;i++){
		for(int j = 0; j<n;j++){
			board2[i][j]='.';
		}
	}
	for(vector<pair<int,int> >::iterator i = v.begin(); i!=v.end();i++){
		int x = i->first,y=i->second;
		for(vector<pair<int, int> >::iterator j = moves.begin(); j!=moves.end();j++){
			int nX,nY;
			nX=x+j->first;
			nY=y+j->second;
			//cout << "nX: " << nX << " nY: " << nY << endl;
			if(nX>=0&&nX<n&&nY>=0&&nY<n){
				board2[nX][nY]='x';
			}
		}
	}
	for(int i = 0; i < n;i++){
		for(int j = 0; j < n; j++){
			if(board2[i][j]=='.' && board[i][j]=='x'){
				stop = true;
				break;
			}
		}
		if(stop)break;
	}
	if(stop){
		cout<<"NO"<<endl;
		return 0;
	} else {
		cout<<"YES"<<endl;
	}
	
	char printBoard[2*n-1][2*n-1];
	for(int i = 0; i < 2*n-1; i++){
		for(int j = 0; j < 2*n-1; j++){
			printBoard[i][j]='.';
		}
	}
	

	for(vector<pair<int,int> >::iterator i = moves.begin(); i!=moves.end(); i++){
		int x = n-1,y=n-1;
		x += i->first,y+=i->second;
		//dx,dy
		if(x>=0 && x < 2*n-1 && y>=0 && y < 2*n-1){
			printBoard[x][y] = 'x';
		}
	}
	printBoard[n-1][n-1] = 'o';
	
	for(int i = 0; i < 2*n-1; i++){
		for(int j = 0; j < 2*n-1; j++){
			cout << printBoard[i][j];
		}
		cout << endl;
	}
}