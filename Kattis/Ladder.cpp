#include<bits/stdc++.h>
using namespace std;
int main(){
    double x,y; scanf("%lf %lf",&x,&y);
    printf("%d\n",(int) ceil(x/sin(y*(M_PI/180.0))));
}
