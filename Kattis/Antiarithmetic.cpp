#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    while(scanf("%d:",&N),N){
        int a[N],k[N];memset(k,-1,sizeof(k));
        for(int i = 0; i < N; ++i){
            scanf("%d",&a[i]);
            k[a[i]]=i;
        }
        bool succ = false;
        for(int i = 0; i < N && !succ; ++i){
            for(int j = 0; j < i && !succ; ++j){
                int tgt = 2*a[i]-a[j];
                if(tgt>=0&&tgt<N&&k[tgt] > i)
                    succ = true;
            }
        }
        if(!succ)
            puts("yes");
        else
            puts("no");
    }
    return 0;
}
