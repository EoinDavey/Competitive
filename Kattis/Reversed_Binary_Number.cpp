#include<cstdio>
using namespace std;

int main(){
    int N; scanf("%d",&N);
    int out = 0;
    while(N){
        out <<= 1;
        out |= (N&1);
        N >>= 1;
    }
    printf("%d\n",out);
    return 0;
}
