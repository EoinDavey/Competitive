#include<iostream>
#include<cstdio>
#include<vector>
#include<map>

using namespace std;

int main(){
    int T; scanf("%d",&T);
    for(int _t =1; _t <= T; _t++){
        printf("Case #%d:\n",_t);
        int N; scanf("%d",&N);
        int a[N];
        map<int,vector<int>> mp;
        for(int i = 0; i < N; i++)
            scanf("%d",&a[i]);
        bool slvd = false;
        for(int i = 1; i < (1<<N) && !slvd; i++){
            int sm = 0;
            for(int j = 0; j < N; j++){
                if((i&(1<<j))!=0)
                    sm+=a[j];
            }
            for(int j = 0; j < mp[sm].size() && !slvd; j++){
                if((mp[sm][j] & i)==0){
                    slvd=true;
                    int ans=mp[sm][j];
                    for(int k = 0; k < N; k++)
                        if((i&(1<<k))!=0)
                            printf("%d ",a[k]);
                    putchar('\n');
                    for(int k = 0; k < N; k++)
                        if((ans&(1<<k))!=0)
                            printf("%d ",a[k]);
                    putchar('\n');
                }
            }
            mp[sm].push_back(i);
        }
        if(!slvd)
            puts("Impossible");
    }
    return 0;
}
