vector<int> buildFailure(string s){
    int n = s.size();
    vector<int> T(n+1,0);
    T[0]=-1;
    int j = 0;
    for(int i = 1; i < n;++i){
        if(s[i]==s[j]){
            T[i]=T[j];
            j++;
        } else{
            T[i] = j;
            j = T[j];
            while(j >= 0 && s[i]!=s[j])
                j = T[j];
            j++;
        }
    }
    T[n] = j;
    return T;
}

vector<int> search(string W, string S){
    int N = S.size();
    auto T=buildFailure(W);
    vector<int> p;
    int k = 0;
    int j = 0;
    while(j < N){
        if(W[k]==S[j]){
            k++;
            j++;
            if(k==W.size()){
                p.push_back(j-k);
                k = T[k];
            }
        }else{
            k = T[k];
            if(k < 0){
                j+=1;
                k+=1;
            }
        }
    }
    return p;
}
