#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[6];
    for(int i = 0; i < 6; ++i)
        scanf("%d",&a[i]);
    for(int i = 0; i < 1<<6; ++i){
        int s1,s2;
        s1=s2=0;
        int acnt = 0;
        for(int j = 0; j < 6; ++j){
            if(i&(1<<j))
                s1+=a[j],acnt++;
            else
                s2+=a[j];
        }
        if(acnt==3 && s1==s2){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
