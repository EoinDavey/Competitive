#include <stdio.h>
#include <iostream>

using namespace std;

int cycle(int n){
	int count = 1;
	while(n!=1){
		count++;
		if(n%2==0) n/=2;
		else n = 3*n + 1;
	}
	return count;
}

int main(){
	int i, j,l;
	while(scanf("%i %i", &i, &j)!=EOF){
		int max = 0;
		int m,n;
		if(i>j){
			m=i;
			n=j;
		} else {
			m=j;
			n=i;
		}
		for(;n<=m;n++){
			l=cycle(n);
			if(l>max)max=l;
		}
		cout << i << " " << j << " " << max << endl;
	}
	return 0;
}