#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll sm = 0;
    int N; scanf("%d",&N);
    for(int i = 2; i <= N; ++i)
        for(int x = 2; x*i <= N; ++x)
            sm += 4LL*x;
    printf("%lld\n", sm);
    return 0;
}
