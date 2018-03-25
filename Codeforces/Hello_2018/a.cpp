#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int N,M; scanf("%lld %lld",&N,&M);
    N = min(40LL,N);
    printf("%lld\n",M&((1LL<<N)-1));
    return 0;
}
