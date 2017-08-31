#include<bits/stdc++.h>
using namespace std;
const int MX_N = 808;
int N,M;
int invCnt[MX_N];

int main(){
    scanf("%d %d",&N,&M);
    int a,b;
    for(int i = 0; i < M; i++){
        scanf("%d %d",&a,&b);
        if(b < a){
            int t = b;
            b = a;
            a = t;
        }
        invCnt[a-1]++;
        invCnt[b-1]--;
    }
    int p[N];
    for(int i =0; i < N; i++){
        p[i+invCnt[i]] = i;
    }
    int lds[N]; memset(lds,0,sizeof(lds));
    lds[0]=1;
    for(int i = 1; i < N; i++){
        lds[i]=1;
        for(int j = 0; j < i; j++){
            if(p[j] > p[i])
                lds[i] = max(lds[i],1 + lds[j]);
        }
    }
    int mx = 0;
    for(int i = 0; i < N; i++)
        mx = max(mx,lds[i]);
    printf("%d\n",mx);
    return 0;
}
