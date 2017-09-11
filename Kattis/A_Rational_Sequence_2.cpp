#include<bits/stdc++.h>
using namespace std;

int dpth;

int find(int p, int q,int d){
    if(p==1 && q==1){
        dpth = d;
        return 0;
    }
    if(p > q)
        return (find(p-q,q,d+1)<<1) | 1;
    else
        return (find(p,q-p,d+1)<<1);
}

int main(){
    int N,P,Q,K;
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%d %d/%d",&K,&P,&Q);
        printf("%d %d\n",K,find(P,Q,0) + (1<<dpth));
    }
}
