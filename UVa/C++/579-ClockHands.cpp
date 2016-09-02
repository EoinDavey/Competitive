#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void calc(double hr, double m){
	hr = hr * 30 + (m/2);
	if(hr >= 360) hr-= 360;
	m = m*6;
	if(m >= 360) m-=360;
	double diff = abs(m-hr);
	double result = min(diff, 360-(diff));
	printf("%.3lf\n",result);
}

int main (){
	double h,m;
	while(scanf("%lf:%lf",&h,&m), h!=0 || m!=0){
		calc(h,m);
	}
	return 0;
}