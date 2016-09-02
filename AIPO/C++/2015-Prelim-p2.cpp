#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;

int main(){
	int N,W,H;
	scanf("%i %i %i",&N,&W,&H);
	double limit = hypot((double)W,(double)H);
	for(int i = 0; i < N; i++){
		int size;
		scanf("%i", &size);
		if(size<=limit){
			cout << "YES" << endl;
		} else cout << "NO" << endl;
	}
	return 0;
}