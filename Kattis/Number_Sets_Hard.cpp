#include<iostream>
#include<cstdio>
#include<vector>
#define ll long long

using namespace std;

const int MX_N=1000011;
int p[2*MX_N];
int sz[2*MX_N];
bool sieve[MX_N];

vector<ll> primes;

int find(int i){return p[i] = (p[i]==i ? i:find(p[i]));}
void join(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa!=pb){
        p[pa]=pb;
        sz[pb]+=sz[pa];
        sz[pa]=0;
    }
}

int main(){
    for(int i = 2; i < MX_N; i++)
        if(!sieve[i]){
            primes.push_back((ll)i);
            for(int j = 2*i; j < MX_N; j+=i)
                sieve[j]=true;
        }
    int T; scanf("%d",&T);
    for(int _t = 1; _t <= T; _t++){
        ll A,B,P; scanf("%lld %lld %lld",&A,&B,&P);
        int len = (int) B-A + 1;
        if(P > 1000000L){
            printf("%d\n",len);
            continue;
        }
        for(int i = 0; i < primes.size(); i++){
            p[MX_N+i]=MX_N+i;
            sz[MX_N+i]=0;
        }
        for(int i = 0; i < len; i++){
            p[i]=i,sz[i]=1;
        }
        for(int i = 0; i < primes.size(); i++){
            ll pr = primes[i];
            if(pr < P)
                continue;
            if(pr > B)
                break;
            for(ll j = pr*(A/pr); j <= B; j+=pr){
                if(j<A)
                    continue;
                if(j > B)
                    break;
                join(j-A,MX_N+i);
            }
        }
        int cnt = 0;
        for(int i = 0; i < len; i++){
            if(sz[i]>0)
                cnt++;
        }
        for(int i= 0; i < primes.size(); i++){
            if(sz[MX_N+i]>0)
                cnt++;
        }
        printf("Case #%d: %d\n",_t,cnt);
    }
    return 0;
}
