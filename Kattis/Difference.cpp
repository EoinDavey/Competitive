#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int MX_M = 2* 10000*10000 + 2;
bitset<MX_M> overall;

int main(){
    int r, m; scanf("%d %d",&r,&m);
    int cnt = 0;
    int smlst = 1;
    vector<int> seq;
    while(!overall[m]){
        overall[r] = true;
        for(int v : seq)
            overall[r-v] = true;
        seq.pb(r);
        while(smlst < 2*10000*10000+1 && overall[smlst])
            ++smlst;
        r+=smlst;
        ++cnt;
    }
    printf("%d\n",cnt);
    return 0;
}
