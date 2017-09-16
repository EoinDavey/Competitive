#include<bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d",&T);
    for(int _t = 1; _t <= T; ++_t){
        int N,K; scanf("%d %d",&N,&K);
        bool fail=false;
        for(int i = 0; i < N && !fail; i++)
            fail |= (K&(1<<i))==0;
        if(fail)
            printf("Case #%d: OFF\n",_t);
        else
            printf("Case #%d: ON\n",_t);
    }
    return 0;
}
