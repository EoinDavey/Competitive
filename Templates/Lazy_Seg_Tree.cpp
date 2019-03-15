ll tree[4 * MX_N + 2];
ll d[4 * MX_N + 2];

void prop(int p, int l, int r){
    tree[p] += d[p] *(r-l+1);
    if(r>l){
        d[2*p]+=d[p];
        d[2*p + 1]+=d[p];
    }
    d[p] = 0;
}

ll rsq(int p, int ql, int qr, int l, int r) {
    prop(p, l, r);
    if(r < ql || l > qr)
        return 0;
    if(l >= ql && r <= qr)
        return tree[p];
    int md = (l+r)/2;
    return rsq(2*p, ql, qr, l, md)
        + rsq(2*p+1, ql, qr, md+1, r);
}

void rng_up(int p, int ql, int qr, ll v, int l, int r){
    prop(p,l,r);
    if(r < ql || l > qr)
        return;
    if(l>=ql && r <= qr){
        d[p]+=v;
        prop(p,l,r);
        return;
    }
    int md=(l+r)/2;
    rng_up(2*p, ql, qr, v, l, md);
    rng_up(2*p+1, ql, qr, v, md+1,r);
    tree[p] = tree[2*p] + tree[2*p+1];
}
