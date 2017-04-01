#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int N;
    cin >> N;
    int a[N];
    int mx; bool mxp = false;
    for(int i = 0; i < N; i++){
        scanf("%d",&a[i]);
        if(a[i]>mx||!mxp)
            mx=a[i],mxp=true;
    }
    printf("%d\n",mx^a[N-1]);
    return 0;
}
