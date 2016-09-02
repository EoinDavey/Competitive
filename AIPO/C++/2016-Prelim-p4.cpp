#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(){
	int n;
	scanf("%i",&n);
	int tree[n+1];
	for(int i = 1; i <= n; i++){
		scanf("%i",&tree[i]);
	}
	for(int i = 1; i <= n; i++){
		int next=i;
		int height = 0;
		while(next!=-1){
			next=tree[next];
			height++;
		}
		cout<<height-1<<endl;
	}
	return 0;
}