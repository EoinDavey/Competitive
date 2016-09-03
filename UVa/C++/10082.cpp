#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>
#include <stdlib.h>
using namespace std;

char keys[] = {'1','2','3','4','5','6','7','8','9','0','-'
	,'=','W','E','R','T','Y','U','I','O','P','[',']','\\','S'
	,'D','F','G','H','J','K','L',';','\'','X','C','V','B','N','M',',','.','/','\0'};
char shif[] = {'`','1','2','3','4','5','6','7','8','9','0'
	,'-','Q','W','E','R','T','Y','U','I','O','P','[',']','A'
	,'S','D','F','G','H','J','K','L',';','Z','X','C','V','B','N','M',',','.','\0'};
	
int search(char c){
	for(int i = 0; i < sizeof(keys)/sizeof(keys[0]);i++){
		if(keys[i]==c)return i;
	}
	return -1;
}

int main(){
	char c;
	stringstream ss;
	while(scanf("%c",&c)==1){
		if(c=='\n'){
			cout << endl;
			continue;
		}
		if(c==' ') cout << " ";
		else cout << shif[search(c)];
	}
	return 0;
}