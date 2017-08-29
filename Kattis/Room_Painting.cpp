#include<cstdio>
#include<algorithm>
using namespace std;

int read_int(){
    int o = 0;
    char c;
    while(1){
        c = getchar_unlocked();
        if(c==' ' || c=='\n')
            break;
        o=(o*10)+(c-48);
    }
    return o;
}

int main(){
    int N,M;
    N=read_int();
    M=read_int();
    int a[N];
    for(int i = 0; i < N; i++)
        a[i] = read_int();
    sort(a,a+N);
    int in;
    long long sm = 0;
    for(int i = 0; i < M; i++){
        in = read_int();
        int * j = lower_bound(a,a+N,in);
        sm+=*j - in;
    }
    printf("%lld\n",sm);
    return 0;
}
