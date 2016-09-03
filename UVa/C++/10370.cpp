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
	int C;
	cin >> C;
	for(int i = 0; i < C; i++){
		double N;
		cin >> N;
		int grades[(int)N];
		double total = 0;
		for(int i = 0; i < N; i++){
			int v;
			scanf("%d",&v);
			total+=v;
			grades[i] = v;
		}
		double avg = total/N;
		int count = 0;
		for(int i = 0; i < N; i++){
			if(grades[i] > avg){
				count++;
			}
		}
		printf("%.3f\%\n",(float)((float) count/(float) N)*100);
	}
	return 0;
}