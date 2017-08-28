#include<bits/stdc++.h>
using namespace std;

int main(){
    int sz[] = {2,3,5,7,11,13,17,19};
    int a[8];
    int done = 0;
    int ans = 1;
    for(int i = 0; i < 8; i++){
        scanf("%d",&a[i]);
        done += ans*a[i];
        ans *= sz[i];
    }
    printf("%d\n",ans-done-1);
    return 0;
}
