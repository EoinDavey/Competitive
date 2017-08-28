#include<bits/stdc++.h>
using namespace std;

bool cups[3];

void swp(int i,int j){
    bool b = cups[i];
    cups[i]=cups[j];
    cups[j]=b;
}

int main(){
    char * buff = new char[55];
    scanf("%s",buff);
    memset(cups,0,sizeof(cups));
    cups[0]=1;
    int n = strlen(buff);
    for(int i = 0; i < n; i++){
        if(buff[i]=='A')
            swp(0,1);
        if(buff[i]=='B')
            swp(1,2);
        if(buff[i]=='C')
            swp(0,2);
    }
    for(int i = 0; i < 3; i++){
        if(cups[i]){
            printf("%d\n",i+1);
            break;
        }
    }
    delete buff;
    return 0;
}
