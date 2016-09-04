#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

int coins[]={50,25,10,5,1};
int memo[8192][5];

int dp(int c,int money){
    if(c==0)return 1;
    if(memo[c][money]!=-1)return memo[c][money];
    int cnt=0;
    for(int i = money; i < 5; i++){
        if(c-coins[i]>=0){
            cnt+=dp(c-coins[i],i);
        }
    }
    return memo[c][money]=cnt;
}

int main(){
    int C=8192;
    for(int i = 0; i <= C;i++){
        memset(memo[i],-1,sizeof(memo[i]));
    }
    while(scanf("%d",&C)==1){
        cout << dp(C,0) << endl;
    }
    return 0;
}
