#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<unordered_set>

using namespace std;

int op[50];
int num[50];
unordered_set<int> dp[40][40];
int N;

int main(){
    int in;
    char c;
    while(1){
        for(int i = 0; i < 30; i++)
            for(int j = 0; j < 30; j++)
                dp[i][j]=unordered_set<int>();
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
        loop:
        N++;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N-i; j++){
                int x = j;
                int y = i+j;
                if(x==y){
                    dp[x][y].insert(num[x]);
                    continue;
                }
                for(int k = x; k < y; k++){
                    for(unordered_set<int>::iterator b = dp[x][k].begin(); b!=dp[x][k].end(); b++){
                        for(unordered_set<int>::iterator e = dp[k+1][y].begin(); e!=dp[k+1][y].end(); e++){
                            dp[x][y].insert((*b) + op[k]*(*e));
                        }
                    }
                }
            }
        }
        printf("%lu\n",dp[0][N-1].size());
    }
    return 0;
}
