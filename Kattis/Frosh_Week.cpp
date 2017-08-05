#include<iostream>
#include<cstdio>

using namespace std;

const int MX_N = 1000111;

int N;
int a[MX_N];
long long cnt=0;

void mergesort(int L, int R){
    if(L>=R)
        return;
    int mid = (L+R)/2;
    mergesort(L,mid);
    mergesort(mid+1,R);
    int n[R-L+1];
    int i = 0;
    int lp = L;
    int rp = mid+1;
    while(rp<=R || lp<=mid){
        if(rp<=R && lp <= mid){
            if(a[rp]<a[lp])
                n[i]=a[rp],rp++,cnt+=((long long) (mid-lp+1));
            else
                n[i]=a[lp],lp++;
        } else if(rp<=R){
            n[i]=a[rp++];
        } else {
            n[i]=a[lp++];
        }
        i++;
    }
    for(int j= L; j <= R; j++)
        a[j]=n[j-L];
}

int main(){ 
    scanf("%d",&N);
    for(int i = 0; i < N; i++)
        scanf("%d",&a[i]);
    mergesort(0,N-1);
    printf("%lld\n",cnt);
    return 0;
}
