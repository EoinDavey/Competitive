#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

int N;
int arr[101];
int memo[101][4];

int dp(int pos, int p, int d){
    if(memo[pos][p]!=-1)return memo[pos][p];
    if(pos>=N)return 0;
    int rest,cont,gym;
    rest = cont = gym = 1000;
    if((arr[pos]==1||arr[pos]==3)&&p!=1){
        cont = dp(pos+1,1,d+1);
    }
    if((arr[pos]==2||arr[pos]==3)&&p!=2){
        gym = dp(pos+1,2,d+1);
    }
    if(cont==1000&&gym==1000){
        rest = dp(pos + 1, 0,d+1) + 1;
    }
    rest = min(rest,cont);
    rest = min(rest,gym);
    return memo[pos][p] = rest;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        scanf("%d",&arr[i]);
    }
    for(int i = 0; i < N;i++){
        memset(memo[i],-1,sizeof(memo[i]));
    }
    cout << dp(0,0,0) << endl;
    return 0;
}
