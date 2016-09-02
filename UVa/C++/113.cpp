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
    double n,p;
	n=p=0;
    while (scanf("%lf %lf", &n, &p) == 2){
        printf("%.0f\n", pow(p, 1 / n));
	}
    return 0;
}