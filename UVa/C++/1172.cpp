#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>

#define ll long long

using namespace std;

int main(){
    int T; scanf("%d",&T);
    for(int _t = 0; _t < T; _t++){
        int N, S;
        string t;
        string nos[1111],sos[1111];
        ll nval[1111],sval[1111];
        scanf("%d",&N);
        for(int i = 0; i < N; i++)
            cin >> t >> nos[i] >> nval[i];
        scanf("%d",&S);
        for(int i = 0; i < S; i++)
            cin >> t >> sos[i] >> sval[i];
        if(N==0 || S==0){
            printf("0 0\n");
            continue;
        }
        ll dp[N][S];
        int nm[N][S];
        ll best = 0;
        memset(dp,0,sizeof(dp));
        memset(nm,0,sizeof(nm));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < S; j++){
                ll mx; int n;
                if((i>0 ? dp[i-1][j]:0) > (j> 0 ? dp[i][j-1]:0)){
                    mx = i > 0 ? dp[i-1][j] : 0;
                    n = i > 0 ? nm[i-1][j] : 0;
                } else {
                    mx = j > 0 ? dp[i][j-1] : 0;
                    n = j > 0 ? nm[i][j-1] : 0;
                }
                if(nos[i]==sos[j]){
                    int c = (i>0&&j>0 ? dp[i-1][j-1]:0) + nval[i] + sval[j];
                    if(c > mx){
                        mx = c;
                        n = (i>0 && j > 0 ? nm[i-1][j-1]:0) + 1;
                    }
                }
                dp[i][j]=mx;
                nm[i][j] = n;
            }
        }
        printf("%lld %d\n",dp[N-1][S-1],nm[N-1][S-1]);
    }
	return 0;
}
