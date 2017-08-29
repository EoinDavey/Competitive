#include<bits/stdc++.h>
using namespace std;
int main(){
    int T; scanf("%d",&T);
    char buff[100];
    while(T-->0){
        int n,m; scanf("%d %d",&n,&m);
        printf("%d\n",n-1);
        gets(buff);
        while(m--)
            gets(buff);
    }
    return 0;
}
