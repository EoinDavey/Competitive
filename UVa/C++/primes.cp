#include<iostream>
#include<cstdio>
#include <vector>

using namespace std;

bool sieve[1000001];
vector<int> primes;

int main(){
    int N = 1000000;
    for(int i = 2; i <= N;i++){
        if(sieve[i])continue;
        primes.push_back(i);
        for(int j = i; j<=N; j+=i){
            sieve[j]=true;
        }
    }
    cout << primes.size() << endl;
    for(int i = 0; i < primes.size();i++){
        cout << primes[i] << endl;
    }
    return 0;
}
