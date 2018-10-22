#include <bits/stdc++.h>
using namespace std;
int main(){
	bool y[366];
	memset(y,0,sizeof(y));	
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		y[a] = 1;
	}
	int dirty=0, h=0, score=0;
	for(int i=0;i<366;i++){
		score+=dirty;
		//make push
		if (y[i]){
			dirty++;
		}
		//if too dirty - clean
		if((i==365&&(dirty+score)>0)||score+dirty>=20){
			h++;
			score =0;
			dirty =0;
		}
	}
	cout << h;
}
