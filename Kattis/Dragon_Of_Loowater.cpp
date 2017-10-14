#include<bits/stdc++.h>
using namespace std;

int main(){
    while(1){
        int N,M; scanf("%d %d",&N,&M);
        if(!(N||M))
            break;
        int hds[N],kns[M];
        for(int i = 0; i < N; ++i)
            scanf("%d",&hds[i]);
        for(int i = 0; i < M; ++i)
            scanf("%d",&kns[i]);
        sort(hds,hds+N);
        sort(kns,kns+M);

        int j = 0;
        int tot = 0;
        bool fail = false;
        for(int i = 0; i < N; ++i){
            while(j < M && kns[j] < hds[i])
                j++;
            if(j >= M){
                fail = true;
                break;
            }
            tot+=kns[j];
            j+=1;
        }
        if(fail)
            puts("Loowater is doomed!");
        else
            printf("%d\n",tot);
    }
}
