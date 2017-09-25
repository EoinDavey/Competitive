#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll MX_N = 10100;

int main(){
    int n; scanf("%d",&n);
    ll l1,l2,lt,a1,a2,at;
    for(int i = 0; i < n; ++i){
        scanf("%lld %lld %lld %lld %lld %lld",&l1,&a1,&l2,&a2,&lt,&at);
        vector<pair<int,int> > soln;
        for(int k = 1; k < MX_N; ++k){
            ll rem = lt - k*l1;
            if(rem > 0 && rem %l2==0 && k*a1 + (rem/l2)*a2 == at)
                soln.push_back({k,rem/l2});
        }
        if(soln.size()==1)
            printf("%d %d\n",soln[0].first,soln[0].second);
        else
            puts("?");
    }
    return 0;
}
