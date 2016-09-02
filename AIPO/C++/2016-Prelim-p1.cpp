#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(){
	char c1[4],c2[4],c3[4];
	string s1,s2,s3,res;
	scanf("%s %s %s",c1,c2,c3);
	s1=c1;
	s2=c2;
	s3=c3;
	bool b1,b2;
	if(s1=="true")b1=true;
	else b1=false;
	if(s3=="true")b2=true;
	else b2=false;
	if(s2=="AND") res = (b1&&b2) ? "true":"false";
	else res = (b1||b2) ? "true":"false";
	cout << res<<endl;
	return 0;
}