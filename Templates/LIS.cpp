int ls[MX_N];
int L[MX_N];
int I[MX_N];

void nlogn(){
    for(int i = 1; i < N+1; ++i)
        I[i]=INF;
    I[0] = -INF;
    int mx = 1;
    for(int i = 0; i < N; ++i){
        int ind = lower_bound(I,I+N+1,ls[i]) - I;
        I[ind] = ls[i];
        L[i] = ind;
        mx = max(mx,ind);
    }
    int prv = INF;
    vector<int> out;
    for(int i = N-1; i >= 0; --i){
        if(ls[i] < prv && L[i]==mx){
            out.push_back(ls[i]);
            prv = ls[i];
            mx--;
        }
    }
}
