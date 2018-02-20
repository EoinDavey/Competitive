#include<bits/stdc++.h>
using namespace std;

constexpr int MX = 1000011;
int N,P,C;
int dif[MX];
int xp[MX];

int main(){
    scanf("%d %d",&N,&P);
    for(int i = 0; i < P;++i)
        scanf("%d",dif+i);
    sort(dif,dif+P);
    scanf("%d",&C);
    for(int i = 0; i < C;++i)
        scanf("%d",xp+i);
    int n[C];
    for(int i = 0; i < C; ++i){
        int * up = upper_bound(dif,dif+P,xp[i]);
        n[i] = up - dif;
    }
    sort(n,n+C,greater<int>());
    if(N==C || (N < C && n[N] != n[N-1]))
        puts("yes");
    else
        puts("no");
    return 0;
}
