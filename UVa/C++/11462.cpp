#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

int ages[101];

int main(){
    int N;
    while(scanf("%d",&N),N!=0){
        memset(ages,0,sizeof(ages));
        int in;
        int mx = 0;
        for(int i = 0; i < N; i++){
            scanf("%d",&in);
            ages[in]++;
            if(in>mx)mx=in;
        }
        for(int i = 1; i <= mx; i++){
            for(int j = 0; j < ages[i]; j++){
               if(i==mx&&j==ages[i]-1)printf("%d\n",i);
               else printf("%d ",i);
            }
        }
    }
    return 0;
}
