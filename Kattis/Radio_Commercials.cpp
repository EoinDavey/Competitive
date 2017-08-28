#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,P; scanf("%d %d",&N,&P);
    int a[N];
    for(int i = 0; i < N; i++){
        scanf("%d",&a[i]);
        a[i]-=P;
    }
    int sm = 0;
    int best = 0;
    for(int i = 0; i < N; i++){
        sm+=a[i];
        if(sm<=0)
            sm=0;
        best = max(best,sm);
    }
    printf("%d\n",best);
    return 0;
}
