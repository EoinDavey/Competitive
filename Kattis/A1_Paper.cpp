#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; scanf("%d",&N);
    --N;
    int a[N],req[N];
    double sqrt2 = sqrt(2.0);
    double tpl = pow(2.0, -3.0/4.0);
    double tot = tpl;
    for(int i = 0; i < N; ++i)
        scanf("%d",&a[i]);
    req[0] = max(2-a[0],0);
    for(int i = 1; i < N; ++i){
        tpl/=sqrt2;
        req[i] = max(2*req[i-1]-a[i],0);
        tot+=tpl*req[i-1];
    }
    if(req[N-1] > 0)
        puts("impossible");
    else
        printf("%.6lf\n",tot);
    return 0;
}
