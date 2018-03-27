#include<bits/stdc++.h>
using namespace std;

const int MX_N=200,INF=1000*1000*1000;
int tree[MX_N*4];
int a[MX_N];
int N;

void construct(int p, int L, int R){
    if(L==R){
        tree[p] = a[L];
        return;
    }
    if(R<L)
        return;
    int md = (L+R)/2;
    construct(2*p,L,md);
    construct(2*p+1,md+1,R);
    tree[p] = min(tree[2*p],tree[2*p+1]);
}

int minR(int p, int L, int R, int l, int r){
    if(r < L || l > R)
        return INF;
    if(l>=L && r<=R)
        return tree[p];
    int md = (l+r)/2;
    return min(minR(2*p,L,R,l,md),minR(2*p+1,L,R,md+1,r));
}

int main(){
    scanf("%d",&N);
    for(int i = 0; i < N;++i)
        scanf("%d",&a[i]);
    construct(1,0,N-1);
    int Q,l,r;
    scanf("%d",&Q);
    for(int i = 0; i < Q; ++i){
        scanf("%d %d",&l,&r);
        printf("%d\n",minR(1,l,r,0,N-1));
    }
    return 0;
}
