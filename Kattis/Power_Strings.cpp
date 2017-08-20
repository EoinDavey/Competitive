#include<bits/stdc++.h>
using namespace std;
int N,lim;
char * buff = new char[2000002];

bool check(int s){
    for(int i = 0; i < N; i+=s){
        for(int j = 0; j < s; j++){
            if(buff[i+j]!=buff[j])
                return false;
        }
    }
    return true;
}

int main(){
    while(scanf("%s",buff)){
        if(*buff=='.')
            break;
        N = strlen(buff);
        lim = (int) ceil(sqrt((double) N));
        int mn = 10000000;
        for(int i = 1; i <= lim; i++){
            if(N%i==0){
                if(check(i))
                    mn=min(mn,i);
                if(check(N/i))
                    mn=min(mn,N/i);
            }
        }
        printf("%d\n",N/mn);
    }
    delete buff;
    return 0;
}
