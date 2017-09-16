#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; scanf("%d",&N);
    int b[N],s[N];
    for(int i = 0; i < N; ++i)
        scanf("%d %d",&b[i],&s[i]);
    int mn = 1000000010;
    for(int i = 1; i < (1<<N); ++i){
        int bs,ss;
        bs = 1; ss = 0;
        for(int j = 0; j < N; ++j)
            if((i&(1<<j))!=0)
                bs*=b[j],ss+=s[j];
        mn = min(mn,abs(bs-ss));
    }
    printf("%d\n",mn);
    return 0;
}
