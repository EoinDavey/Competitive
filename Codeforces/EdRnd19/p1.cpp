#include<cstdio>
#include<vector>

using namespace std;

const int mx_n = 100001;
vector<int> primes;
bool sieve[mx_n];

int main(){
    int N, K;
    scanf("%d %d",&N,&K);
    for(int i = 2; i <= N; i++){
        if(!sieve[i]){
            for(int j = i; j <= N; j+=i)
                sieve[j] = true;
            primes.push_back(i);
        }
    }
    int cnt = 0;
    int tN = N;
    vector<int> ans;
    for(int i = 0; i < primes.size(); i++){
        while(tN%primes[i] == 0){
            tN/=primes[i];
            ans.push_back(primes[i]);
            cnt++;
        }
    }
    if(cnt >= K){
        for(int i = 0; i < K-1; i++)
            printf("%d ",ans[i]);
        int r = 1;
        for(int i = K-1; i < ans.size(); i++)
            r*=ans[i];
        printf("%d\n",r);
    }
    else
        printf("-1\n");
    return 0;
}
