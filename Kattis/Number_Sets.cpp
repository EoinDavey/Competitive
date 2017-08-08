#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

const int MX_N=1011;
int p[MX_N];
bool sieve[MX_N];

int cnt;
vector<int> primes;

int find(int i){return p[i] = (p[i]==i ? i:find(p[i]));}
void join(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa!=pb){
        p[pa]=pb;
        cnt--;
    }
}

int main(){
    for(int i = 2; i < MX_N; i++)
        if(!sieve[i]){
            primes.push_back(i);
            for(int j = 2*i; j < MX_N; j+=i)
                sieve[j]=true;
        }
    int T; scanf("%d",&T);
    for(int _t = 1; _t<=T; _t++){
        int A,B,P; scanf("%d %d %d",&A,&B,&P);
        cnt=B-A+1;
        for(int i= A; i <= B; i++)
            p[i]=i;
        for(int i = 0; i < primes.size(); i++){
            int pr = primes[i];
            if(pr < P)
                continue;
            if(pr > B)
                break;
            for(int j = pr*(A/pr); j <= B; j+=pr){
                if(j < A)
                    continue;
                for(int k = j+pr; k <= B; k+=pr){
                    join(j,k);
                }
            }
        }
        printf("Case #%d: %d\n",_t,cnt);
    }
    return 0;
}
