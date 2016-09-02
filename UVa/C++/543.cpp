#include<iostream>
#include<cstdio>
#include <vector>

using namespace std;

bool sieve[1000001];
bool prime[1000001];

int main(){
    int N;
    for(int i = 2; i <= 1000000;i++){
        if(sieve[i])continue;
        prime[i]=true;
        for(int j = i; j<=1000000; j+=i){
            sieve[j]=true;
        }
    }
    while(cin >> N,N!=0){
        for(int i = N; i >= 2; i--){
            if(prime[i]&&prime[N-i]){
                printf("%d = %d + %d\n",N,N-i,i);
                break;
            }
        }
    }
    return 0;
}
