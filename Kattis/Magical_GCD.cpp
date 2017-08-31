#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX_N = 100001;
map<ll,int> mps[MX_N];
ll a[MX_N];

int main(){
    int T; scanf("%d",&T);
    while(T--){
        int N; scanf("%d",&N);
        for(int i = 0; i < N; i++){
            scanf("%lld",&a[i]);
            mps[i].clear();
        }
        mps[0][a[0]] = 0;
        ll mx = a[0];
        for(int i = 1; i < N; i++){
            mps[i][a[i]]=i;
            for(auto j = mps[i-1].begin(); j != mps[i-1].end(); j++){
                ll g = __gcd(j->first,a[i]);
                if(mps[i].find(g)==mps[i].end())
                    mps[i][g]=j->second;
                else
                    mps[i][g] = min(mps[i][g],j->second);
            }
            for(auto j = mps[i].begin(); j != mps[i].end(); j++)
                mx = max(mx, j->first*(i-j->second + 1));
        }
        printf("%lld\n",mx);
    }
    return 0;
}
