#include<bits/stdc++.h>
using namespace std;

const int MX_N  = 5000;
int N;
int r[MX_N];

inline int n2(int x){
    int i = 1;
    while(x > i)
        i <<= 1;
    return i;
}

inline void update(map<int,double>& mp, const map<int,double>& lmp, const map<int,double>& rmp){
    if(rmp.empty()){
        for(auto a : lmp)
            mp[a.first] = a.second;
        return;
    }
    for(auto a : lmp){
        if(r[a.first]==0)
            continue;
        for(auto b : rmp){
            mp[a.first]+=b.second*((1.0*r[a.first])/(r[a.first]+r[b.first]));
        }
        mp[a.first]*=a.second;
    }
}

void trav(map<int,double>& mp, int L, int sz){
    if(sz==1){
        mp[L]=1.0;
        return;
    }
    int hf = sz>>1;
    map<int,double> lmp,rmp;
    trav(lmp,L,hf);
    trav(rmp,L+hf,hf);
    update(mp,lmp,rmp);
    update(mp,rmp,lmp);
}

int main(){
    scanf("%d",&N);
    for(int i = 0; i < N; ++i)
        scanf("%d",r+i);
    int t = r[0];
    r[0] = r[N-1];
    r[N-1] = t;
    sort(r,r+N-1,greater<int>());
    int lo = 2*N - n2(N);
    N = n2(N);
    int nr[MX_N];
    for(int i = 0; i < lo; ++i)
        nr[i] = r[i];
    int z = 0;
    for(int i = lo; i < N; i+=2,z++){
        nr[i] = r[i-z];
        nr[i+1]=0;
    }
    for(int i = 0; i < N; ++i)
        r[i] = nr[i];
    map<int,double> pr;
    trav(pr,0,N);
    printf("%.8lf\n",(--pr.end())->second);
    return 0;
}
