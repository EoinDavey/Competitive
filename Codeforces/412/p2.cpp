#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int newPos(int a[25], int s){
    int i = (s / 50) % 475;
    for(int j = 0; j < 25; j++){
        i = (i*96 + 42) % 475;
        a[j] = 26+i;
    }
}

int main(){
    int P,X,Y; cin >> P >> X >> Y;
    int pos[25];
    newPos(pos,X);
    int uLim = 23750;
    int bLim = X;
    for(; bLim >= Y+50; bLim-=50){}
    int ans = 0;
    for(int i = bLim; i <= uLim && ans == 0; i+=50){
        newPos(pos, i);
        for(int j = 0; j < 25; j++)
            if(pos[j] == P){
                ans = i;
                break;
            }
    }
    if(ans < X) 
        printf("0\n");
    else printf("%d\n",(int) ceil(((double)ans - X)/100.0));
    return 0;
}
