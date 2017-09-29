#include<bits/stdc++.h>
using namespace std;

constexpr int MX_N = 1000001;

int a[MX_N];
int N,K;

bool check(int d){
    int lbound = 0;
    for(int i = 0; i < N; ++i){
        int ubound = 2*K*i;
        bool fail = true;
        for(; lbound <= ubound; ++lbound){
            if(a[lbound+1]-a[lbound] <= d){
                fail = false;
                lbound+=2;
                break;
            }
        }
        if(fail)
            return false;
    }
    return true;
}

int main(){
    scanf("%d %d",&N,&K);
    for(int i = 0; i < 2*N*K; ++i)
        scanf("%d",&a[i]);
    sort(a,a+2*N*K);
    int L,R;
    L=0,R=1000000000;
    while(1){
        if(L>=R)
            break;
        int md = (L+R)/2;
        if(check(md)){
            R = md;
        } else {
            L = md+1;
        }
    }
    printf("%d\n",R);
    return 0;
}
