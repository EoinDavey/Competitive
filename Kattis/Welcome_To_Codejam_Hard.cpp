#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr int MD=10000;

int N;
char s[550];
char wc[] = "welcome to code jam";
int memo[550][20];

int dp(int u, int k){
    if(memo[u][k] != -1)
        return memo[u][k];
    if(k==0){
        int wys = 0;
        for(int i = 0; i <= u; ++i)
            if(s[i]==wc[0])
                wys++;
        return memo[u][k] = wys%MD;
    }
    int wys = 0;
    for(int i = 0; i <= u; ++i){
        if(s[i]==wc[k]){
            wys = (wys+dp(i,k-1)) % MD;
        }
    }
    return memo[u][k] = wys;
}

int main(){
    int T; scanf("%d",&T);
    gets(s);
    for(int i = 1; i <=T; ++i){
        gets(s);
        N = strlen(s);
        memset(memo,-1,sizeof(memo));
        int n = dp(N-1,18);
        printf("Case #%d: ",i);
        if(n < 10)
            printf("000%d\n",n);
        else if(n < 100)
            printf("00%d\n",n);
        else if(n < 1000)
            printf("0%d\n",n);
        else
            printf("%d\n",n);
    }
    return 0;
}
