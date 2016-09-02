#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(){
	int sX,sY,tX,tY,n,min,minX,minY;
	min = 100000;
	scanf("%i %i %i",&sX,&sY,&n);
	for(int i = 0; i < n; i++){
		scanf("%i %i",&tX,&tY);
		int dis = abs(tX-sX) + abs(tY-sY);
		if(dis<min){
			min=dis;
			minX = tX;
			minY=tY;
		}
	}
	cout << minX<< " " << minY << endl;
	return 0;
}