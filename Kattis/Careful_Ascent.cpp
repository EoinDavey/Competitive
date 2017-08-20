#include<bits/stdc++.h>
using namespace std;

int main(){
    int X,Y; scanf("%d %d",&X,&Y);
    int N; scanf("%d",&N);
    int l,r;
    double f;
    double s = 0.0;
    int rem = Y;
    for(int i = 0; i < N; i++){
        scanf("%d %d %lf",&l,&r,&f);
        int sz = r-l;
        rem -= sz;
        s+= sz*f;
    }
    s += rem;
    printf("%.8lf\n",X/s);
    return 0;
}
