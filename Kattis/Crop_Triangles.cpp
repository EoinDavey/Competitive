#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
vector<pl> seq;
int N;
ll A,B,C,D,M;
ll sets[9];

void genSeq(ll x0, ll y0){
    ll X,Y;
    X = x0; Y = y0;
    seq.push_back({X,Y});
    for(int i = 0; i < N-1; ++i){
        X = (A*X + B) %M;
        Y = (C*Y + D) %M;
        seq.push_back({X,Y});
    }
}

int main(){
    int T; scanf("%d",&T);
    for(int t = 1; t <= T; ++t){
        ll x0,y0;
        scanf("%d %lld %lld %lld %lld %lld %lld %lld",&N,&A,&B,&C,&D,&x0,&y0,&M);
        seq.clear();
        memset(sets,0,sizeof(sets));
        genSeq(x0,y0);
        for(const auto &p : seq)
            sets[3*(p.first%3) + p.second%3]++;
        ll cnt = 0LL;
        for(int i = 0; i < 9; ++i)
            cnt+=(sets[i]*(sets[i]-1)*(sets[i]-2))/6;
        for(int i = 0; i < 9; ++i)
            for(int j = i+1; j < 9; ++j)
                for(int k = j+1; k < 9; ++k)
                    if((((i/3) + (j/3) + (k/3)) %3 == 0) &&
                            (((i%3) + (j%3) + (k%3)) % 3 ==0))
                        cnt+=sets[i]*sets[j]*sets[k];
        printf("Case #%d: %lld\n",t,cnt);
    }
    return 0;
}
