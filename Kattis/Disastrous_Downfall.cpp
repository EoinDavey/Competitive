#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX_N = 1000*1000;
const int MD = 199933;
int N,R,K;
ll A,B;
int bckts[MX_N];
int jmp[MX_N];

inline int nxt(int X){ return (((A*((ll)X))%N) + B)%N;} 

int find(int u){ return jmp[u] = (u==jmp[u] || u==-1) ? u : find(jmp[u]); }

int main(){
    int x0;
    scanf("%d %d %d %d %lld %lld",&N,&R,&K,&x0,&A,&B);
    for(int i = 0; i < N; ++i)
        jmp[i]=i;
    int scr = 0;
    for(int i = 0; i < R; ++i){
        x0 = nxt(x0);
        int j = find(x0);
        if(j==-1){
            puts("OVERFLOW");
            return 0;
        }
        bckts[j]++;
        if(bckts[j]==K){
            jmp[j] = j-1;
        }
        scr = (53*scr + j) % MD;
    }
    printf("%d\n",scr);
    return 0;
}
