#include<cstdio>
#include<cmath>

using namespace std;

int main(){
    int N,K; scanf("%d %d",&N,&K);
    int a[N];
    int tot = 0;
    for(int i = 0; i < N; i++){
        scanf("%d",&a[i]);
        tot+=a[i];
    }
    int i;
    if((K*10-5)*N <= tot*10){
        puts("0\n");
        return 0;
    }
    for(i = 1;1;i++){
        tot+=K;
        if((K*10-5)*(N+i) <= (tot*10))
            break;
    }
    printf("%d\n",i);
}
