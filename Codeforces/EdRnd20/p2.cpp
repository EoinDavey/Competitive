#include<cstdio>
#include<iostream>

using namespace std;

const int INF = 1000000;

int main(){
    int N; scanf("%d",&N);
    int a[N];
    int dif[N];
    for(int i = 0; i < N; i++)
        scanf("%d",&a[i]), dif[i]=INF;
    int prev = -1;
    for(int i = 0; i < N; i++){
        if(a[i]==0)prev=i;
        dif[i] = (prev!=-1) ? i - prev : INF;
    }
    prev = -1;
    for(int i = N-1; i >= 0; i--){
        if(a[i]==0)prev=i;
        dif[i] = min(dif[i], (prev!=-1) ?prev - i : INF);
    }
    for(int i = 0; i < N; i++)
        printf("%d ",dif[i]);
    printf("\n");
    return 0;
}
