#include<stdio.h>

int read_int(){
    int o=0;
    char c;
    while(1){
        c = getchar_unlocked();
        if(c >= '0' && c <= '9')
            break;
    }
    while(c >= '0' && c <= '9'){
        o=o*10 + c-'0';
        c=getchar_unlocked();
    }
    return o;
}

int main(){
    int a,b,c,N;
    N= read_int();
    while(N-->0){
        a=read_int();
        b=read_int();
        c=read_int();
        if(a+b==c || a-b == c || b-a ==c || a*b == c || a==b*c || b==a*c)
            puts("Possible");
        else
            puts("Impossible");
    }
}
