#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,M; scanf("%d %d",&N,&M);
    int a[N];
    for(int i = 0; i < N; i++)
        scanf("%d",&a[i]);
    int l,r,x;
    for(int i = 0; i < M; i++){
        scanf("%d %d %d",&l,&r,&x);
        l--;r--;x--;
        int c = a[x];
        int cnt=0;
        for(int j = l; j <= r; j++)
            if(a[j] < c)
                cnt++;
        if(l+cnt == x)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
