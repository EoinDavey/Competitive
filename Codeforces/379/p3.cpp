#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

int main(){
    long long int N,M,K,X,S; cin >> N >> M >> K >> X >> S;
    long long int times[M];
    long long int timeCosts[M];
    for(int i = 0; i < M; i++)
        scanf("%lld",&times[i]);
    for(int i = 0; i < M; i++)
        scanf("%lld",&timeCosts[i]);
    long long int instant[K];
    long long int instantCosts[K];
    for(int i = 0; i < K; i++)
        scanf("%lld",&instant[i]);
    for(int i = 0; i < K; i++)
        scanf("%lld",&instantCosts[i]);
    long long int minTime;
    long long int p = upper_bound(instantCosts, instantCosts+K, S) - instantCosts - 1;
    if(instantCosts[p]<=S){
        minTime = X * (N-instant[p]);
    } else minTime = X * N;
    long long int tTime;
    for(long long int i = 0; i < M; i++){
        if(times[i] >= X || timeCosts[i] > S) continue;
        p = upper_bound(instantCosts, instantCosts + K, S - timeCosts[i]) - instantCosts - 1;
        if(instantCosts[p] <= S-timeCosts[i]){
             tTime = times[i] * (N - instant[p]);
        } else tTime = times[i] * N;
        if(tTime < minTime) minTime = tTime;
    }
    cout << minTime << endl;
    return 0;
}
