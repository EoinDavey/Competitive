#include<iostream>
#include<cstdio>

using namespace std;

char buff[20];

int main(){
    setbuf(stdout,NULL);
    int L,R,m;
    L=0;R=1000;
    while(true){
        m = (L+R)/2;
        printf("%d\n",m);
        scanf(" %s",buff);
        if(buff[0]=='l')
            R = m-1;
        else if(buff[0]=='h')
            L=m+1;
        else
            break;
    }
    return 0;
}
