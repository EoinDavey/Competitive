#include<bits/stdc++.h>
using namespace std;

constexpr int MX_S=20010,MX_N=101,INF=200;
int S,N;
int v[MX_N];
int dst[MX_N][MX_S];

int main(){
    int T; scanf("%d",&T);
    while(T --> 0){
        scanf("%d",&S);
        scanf("%d",&N);
        for(int i = 0; i < N;++i)
            scanf("%d",&v[i]);
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < MX_S; ++j)
                dst[i][j]=INF;
        for(int i= 0; i < N; ++i)
            dst[i][0]=0;
        for(int i = 0; i < N; ++i)
            dst[i][v[i]]=1;
        for(int i = 1; i < N; ++i){
            for(int j = 0; j < MX_S; ++j){
                if(dst[i-1][j] < INF){
                    dst[i][j]=min(dst[i][j],dst[i-1][j]);
                    if(j+v[i] < MX_S)
                        dst[i][j+v[i]]=min(dst[i][j+v[i]], dst[i-1][j]+1);
                }
            }
        }
        for(int i = S; i < MX_S; ++i){
            if(dst[N-1][i]<INF){
                printf("%d %d\n",i,dst[N-1][i]);
                break;
            }
        }
    }
    return 0;
}
