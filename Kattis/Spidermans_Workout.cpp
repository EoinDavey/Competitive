#include<bits/stdc++.h>
using namespace std;

constexpr int MX_M=41,MX_H=1001,INF=10000;
int dp[MX_M][MX_H];
int p[MX_M][MX_H];
int h[MX_M];
int M;

int main(){
    int T; scanf("%d",&T);
    while(T --> 0){
        scanf("%d",&M);
        for(int i = 0; i < M; ++i)
            scanf("%d",&h[i]);
        for(int i = 0; i < M; ++i)
            for(int j = 0; j < MX_H; ++j)
                dp[i][j] = INF;
        dp[0][h[0]]=h[0];
        for(int i = 1; i < M; ++i){
            for(int j = 0; j < MX_H; ++j){
                if(dp[i-1][j] < INF){
                    if(j >= h[i]){
                        if(dp[i-1][j] < dp[i][j-h[i]]){
                            dp[i][j-h[i]] = dp[i-1][j];
                            p[i][j-h[i]] = j;
                        }
                    }
                    int d = max(dp[i-1][j],j+h[i]);
                    if(d < dp[i][j+h[i]]){
                        dp[i][j+h[i]] = d;
                        p[i][j+h[i]] = j;
                    }
                }
            }
        }
        if(dp[M-1][0] < INF){
            vector<char> v;
            int h = 0;
            for(int i = M-1; i > 0; i--){
                if(p[i][h] > h){
                    v.push_back('D');
                } else
                    v.push_back('U');
                h = p[i][h];
            }
            putchar('U');
            for(auto i = v.rbegin(); i != v.rend(); i++)
                putchar(*i);
            putchar('\n');
        } else
            puts("IMPOSSIBLE");
    }
    return 0;
}
