#include<bits/stdc++.h>
using namespace std;

bool isprime(int x){
    for(int i = 2; i <= sqrt(x); ++i){
        if(x%i==0)
            return false;
    }
    return true;
}

int calc(int x){
    if(isprime(x))
        return 1;
    for(int i = 2; i < x; ++i)
        if(x % i==0)
            return calc(i) + calc(x/i);
}

int main(){
    int X; scanf("%d",&X);
    printf("%d\n",calc(X));
    return 0;
}
