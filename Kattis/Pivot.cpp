#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int N; scanf("%d",&N);
    int a[N];
    int mx[N];
    int mn[N];
    for(int i = 0; i < N; i++)
        scanf("%d",&a[i]);
    mx[0]=a[0];
    for(int i=1; i < N; i++)
        mx[i]=max(a[i-1],mx[i-1]);
    mn[N-1]=a[N-1];
    for(int i = N-2; i >=0; i--)
        mn[i]=min(a[i+1],mn[i+1]);
    int cnt = 0;
    for(int i = 1; i < N-1; i++)
        if(mx[i]<=a[i] && mn[i] > a[i])
            cnt++;
    if(N>=2){
        if(min(mn[1],a[1])>a[0])
            cnt++;
        if(max(mx[N-2],a[N-2]) <= a[N-1])
            cnt++;
        printf("%d\n",cnt);
    } else
        puts("1");
    return 0;
}
