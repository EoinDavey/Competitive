#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<set>

using namespace std;

int op[50];
int num[50];
set<int> dp[40][40];
bool dpset[40][40];
int N;

void solve(int l, int r){
    if(l==r){
        dp[l][r].insert(num[l]);
        return;
    }
    if(dp[l][r].size() > 0)
        return;
    for(int i = l; i < r; i++){
        int m = op[i];
        solve(l,i); solve(i+1,r);
        for(set<int>::iterator b = dp[l][i].begin(); b!=dp[l][i].end(); b++){
            for(set<int>::iterator e = dp[i+1][r].begin(); e!=dp[i+1][r].end(); e++){
                dp[l][r].insert((*b) + m*(*e));
            }
        }
    }
    return;
}

int main(){
    int in;
    char c;
    while(1){
        memset(dpset,0,sizeof(dpset));
        for(int i = 0; i < 30; i++)
            for(int j = 0; j < 30; j++)
                dp[i][j]=set<int>();
        for(N = 0;1;N++){
            if(scanf(" %d",&in) <= 0)
                return 0;
            num[N]=in;
            while(1){
                if(scanf("%c",&c)==0 || c==EOF)
                    return 0;
                if(c=='\n')
                    goto loop;
                if(c!=' ')
                    break;
            }
            op[N] = c == '+' ? 1:-1;
        }
        loop: solve(0,N);
        printf("%lu\n",dp[0][N].size());
    }
    return 0;
}
