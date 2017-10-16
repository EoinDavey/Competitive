#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int main(){
    bool fail = false;
    int F; scanf("%d",&F);
    for(int f = 0; f < F && !fail; ++f){
        int T,N; scanf("%d %d",&T,&N);
        bool dp[T+1]; memset(dp,1,sizeof(dp));
        bool ndp[T+1];
        int l,r;
        for(int i = 0; i < N; ++i){
            memset(ndp,0,sizeof(ndp));
            scanf("%d %d",&l,&r);
            int ln = r-l;
            for(int j = 0; j <= T; ++j){
                if(!dp[j])
                    continue;
                if(j-ln>=0)
                    ndp[j-ln]=true;
                if(j+ln<=T)
                    ndp[j+ln]=true;
            }
            memcpy(dp,ndp,(T+1)*sizeof(bool));
        }
        bool tfail = true;
        for(int i = 0; i <= T; ++i)
            if(dp[i])
                tfail=false;
        fail |= tfail;
    }
    if(fail)
        puts("impossible");
    else
        puts("possible");
    return 0;
}
