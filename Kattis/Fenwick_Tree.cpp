#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MX_N = 5000*1000 + 2;
ll tree[MX_N];
int N;

inline int lsOne(int i){
    return i&(-i);
}

inline void update(int k,ll v){
    for(; k<=N; k+=lsOne(k))
        tree[k]+=v;
}

inline ll query(int k){
    ll cnt=0;
    for(; k; k-=lsOne(k)){
        cnt+=tree[k];
    }
    return cnt;
}

int main(){
    int Q;
    scanf("%d %d",&N,&Q);
    char c; int x; ll y;
    for(int i = 0; i < Q; ++i){
        scanf(" %c",&c);
        if(c=='+'){
            scanf("%d %lld",&x,&y);
            update(x+1,y);
        } else{
            scanf("%d",&x);
            printf("%lld\n",query(x));
        }
    }
}
