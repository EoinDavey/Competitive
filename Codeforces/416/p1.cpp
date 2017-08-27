#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b; scanf("%d %d",&a,&b);
    int md = 1;
    int cur = 1;
    while(1){
        if(md==1){
            if(a < cur){
                puts("Vladik");
                break;
            }
            a-=cur;
        } else {
            if(b < cur){
                puts("Valera");
                break;
            }
            b-=cur;
        }
        cur++;
        md=1-md;
    }
    return 0;
}
