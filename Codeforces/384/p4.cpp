#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int N; cin >> N;
    if(N==1)
        printf("-1\n");
    else printf("%d %d %d\n",N,N+1,N*(N+1));
    return 0;
}
