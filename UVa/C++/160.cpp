#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

bool prime[101];
bool sieve[101];
vector<int> primes;
int memo[101][25];

int main(){
    for(int i = 2; i <= 100; i++){
        if(!sieve[i]){
            primes.push_back(i);
            prime[i]=true;
            for(int j = i;j<=100;j+=i){
                sieve[j]=true;
            }
        }
    }
    memset(memo,-1,sizeof(memo));
    for(int i = 2; i <=100; i++){
        int runner = i;
        for(int j = 0; j < primes.size(); j++){
            int cnt = 0;
            while(runner%primes[j]==0){
                runner/=primes[j];
                cnt++;
            }
            memo[i][j] = cnt;
        }
    }
    int N;
    while(scanf("%d",&N),N!=0){
        if(N>99)printf("%d! = ",N);
        else if(N>9) printf(" %d! = ",N);
        else printf("  %d! = ",N);
        int out[primes.size()];
        memset(out,0,sizeof(out));
        int mx = 0;
        for(int i = 2; i <= N; i++){
            for(int j = 0; j < primes.size(); j++){
                out[j]+=memo[i][j];
                if(memo[i][j]>0&&j>mx)mx=j;
            }
        }
        for(int i = 0; i <=mx;i++){
            if(i==15){
                printf("       ");
            }
            if(i==14||i==mx){
                if(out[i]>9)printf("%d\n",out[i]);
                else printf(" %d\n",out[i]);
            }else{
                if(out[i] > 9) printf("%d ",out[i]);
                else printf(" %d ",out[i]);
            }
        }
    }
    return 0;
}
