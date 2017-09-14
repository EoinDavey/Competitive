#include<bits/stdc++.h>
using namespace std;

int N,S,R;

int main(){
    scanf("%d %d %d",&N,&S,&R);
    bool s[N]; memset(s,0,sizeof(s));
    bool r[N]; memset(r,0,sizeof(r));
    int _in;
    for(int i = 0; i < S; ++i){
        scanf("%d",&_in);--_in;
        s[_in]=true;
    }
    for(int i = 0; i < R; ++i){
        scanf("%d",&_in);--_in;
        r[_in]=true;
    }
    int mn=10;
    for(int i = 0; i < (1<<N); ++i){
        bool k[N]; memset(k,0,sizeof(k));
        for(int j = 0; j < N; ++j){
            if(s[j] && !r[j]){
                if(j < N-1 && r[j+1] && !s[j+1] && (i&(1<<(j+1)))==0)
                    k[j]=true;
                else if(j > 0 && r[j-1] && !s[j-1] && (i&(1<<(j-1)))!=0)
                    k[j]=true;
                else
                    k[j]=false;
            } else
                k[j]=true;
        }
        int cnt=0;
        for(int j = 0; j < N; ++j)
            if(!k[j])
                cnt++;
        mn=min(mn,cnt);
    }
    printf("%d\n",mn);
    return 0;
}
