int tree[MX_N];
int N;
int lsOne(int i){ return i&(-i); }
void update(int k,int v){
    for(; k<MX_N; k+=lsOne(k))
        tree[k]+=v;
}
int query(int k){
    int cnt=0;
    for(; k; k-=lsOne(k)){
        cnt+=tree[k];
    }
    return cnt;
}
