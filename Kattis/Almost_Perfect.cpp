#include<bits/stdc++.h>
using namespace std;

int smdiv(int n){
    int l = sqrt(n);
    int sm = 1;
    for(int i = 2; i <=l; ++i){
        if(n%i==0){
            sm+=i;
            if(i*i!=n)
                sm+=n/i;
        }
    }
    return sm;
}

int main(){
    int n;
    while(~scanf("%d",&n)){
        int x = smdiv(n);
        if(n==x)
            printf("%d perfect",n);
        else if(abs(n-x) <= 2)
            printf("%d almost perfect",n);
        else
            printf("%d not perfect",n);
        putchar('\n');
    }
    return 0;
}
