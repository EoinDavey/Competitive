#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long

using namespace std;

ll n,x,y,w,h;
int out[40][40];

void build(ll x1, ll y1, ll sz, int mod){
    if(x1+sz-1<x || y1+sz-1 < y)
        return;
    if(x+h-1 < x1 || y+w-1 < y1)
        return;
    if(sz==1){
        out[x1-x][y1-y]=mod;
        return;
    }
    ll subSz = sz>>1;
    build(x1,y1,subSz,mod);
    build(x1+subSz,y1,subSz,mod);
    build(x1+subSz,y1+subSz,subSz,-1*mod);
    build(x1,y1+subSz,subSz,mod);
}

int main(){
    int T; scanf("%d",&T);
    while(T --> 0){
        scanf("%lld %lld %lld %lld %lld",&n,&y,&x,&w,&h);
        memset(out,0,sizeof(out));
        build(0,0,n,1);
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++)
                printf("%d ",out[i][j]);
            putchar('\n');
        }
        if(T>0)
            putchar('\n');
    }
    return 0;
}
