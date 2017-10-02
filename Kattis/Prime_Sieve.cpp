#include<cstdio>
#include<stdint.h>
#include<cmath>

constexpr int MX_N = 3125011;
uint32_t sieve[MX_N];

int main(){
    int n,q; scanf("%d %d",&n,&q);
    sieve[0] |= 1;
    int sq = (int) ceil(sqrt(n))+2;
    for(long i = 3; i <=sq; i+=2){
        if((sieve[i>>5]&(1<<(i & 31)))==0){
            for(int j = i*i; j <= n; j+=2*i){
                sieve[j>>5] |= (1<<(j & 31));
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < (n>>5); ++i)
        cnt+=__builtin_popcount(~sieve[i]);
    int _x = n>>5;
    int x = sieve[_x];
    for(int i = 0; (_x << 5) + i <= n; ++i)
        if((x&(1<<i))==0)
            cnt++;
    cnt -= n/2;
    printf("%d\n",cnt);
    int in;
    for(int i = 0; i < q; ++i){
        scanf("%d",&in);
        if(in<=1 || (in%2==0 && in != 2)){
            puts("0");
            continue;
        }
        if((sieve[in>>5]&(1<<(in & 31)))==0){
            puts("1");
        } else {
            puts("0");
        }
    }
    return 0;
}
