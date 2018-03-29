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

void update(int p, int L, int R, int ind,int v){
    if(L==R){
        a[ind] = v;
        tree[p] = v;
        return;
    }
    int md = (L+R)/2;
    if(ind <= md)
        update(2*p,L,md,ind,v);
    else
        update(2*p+1,md+1,R,ind,v);
    tree[p] = min(tree[2*p],tree[2*p+1]);
}

int rmq(int p, int L, int R, int l, int r){
    if(r < L || l > R)
        return INF;
    if(l>=L && r<=R)
        return tree[p];
    int md = (l+r)/2;
    return min(rmq(2*p,L,R,l,md),rmq(2*p+1,L,R,md+1,r));
}
