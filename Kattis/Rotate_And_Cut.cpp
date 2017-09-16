#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,T;
    char buff[2002];
    scanf("%d",&T);
    while(T --> 0){
        scanf("%d %s",&N,buff);
        bool usd = false;
        int L = 0;
        int R= strlen(buff)-1;
        for(int i = 0; i< N; ++i){
            usd = !usd;
            int ln = R-L+1;
            int q = ln/4;
            if(q == 0)
                break;
            if(usd)
                L+=q;
            else
                R-=q;
        }
        for(int i = L; i <= R; ++i)
            putchar_unlocked(buff[i]);
        putchar('\n');
    }
    return 0;
}
