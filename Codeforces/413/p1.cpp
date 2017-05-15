#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int n,t,k,d;
    scanf("%d %d %d %d",&n,&t,&k,&d);
    int currt=0;
    while (currt <= d) {
        n -= k;
        currt += t;
    }
    if (n > 0) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}
