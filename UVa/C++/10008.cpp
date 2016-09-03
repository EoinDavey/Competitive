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
#include <stdint.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	char c[] = {'a','z','A','Z'};
	int a = c[0];
	int z = c[1];
	int A = c[2];
	int Z = c[3];
	long long az[26];
	memset(az,0,sizeof(az));
	char ch;
	while(scanf("%c",&ch)!=EOF){
		int i = ch;
		if(i>=97&&i<=122){
			az[i-a]++;
		} else if(i>=65&&i<=90){
			az[i-A]++;
		}
	}
	bool changed = false;
	do{
		changed = false;
		long long max = 0;
		int in=0;
		for(int i = 0; i < 26;i++){
			if(az[i]>max){
				max = az[i];
				in=i;
				changed = true;
			}
		}
		if(az[in]==0) continue;
		printf("%c %lld\n",(char)in + A, az[in]);
		az[in]=0;
	} while(changed);
	return 0;
}