#include<bits/stdc++.h>
using namespace std;
const int MX_NK = 1000*1000+2;
int p[MX_NK];
int N,K;

int find(int i){return p[i] = (p[i]==i ? i : find(p[i]));}
int join(int a, int b) { p[find(a)]=find(b);}

int main(){
    for(int i = 0; i < MX_NK; ++i)
        p[i]=i;
    scanf("%d %d",&N,&K);
    int a,b;
    while(K-->0){
        scanf("%d %d",&a,&b);
        a--;b--;
        join(a,b);
    }
    for(int i = 0; i < N; ++i){
        if(find(i) != find(N-i-1)){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
