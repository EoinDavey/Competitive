#include<bits/stdc++.h>
#define pb push_back
#define mdadd(x,y) ((x+y)%MOD+MOD)%MOD
using namespace std;
typedef pair<int,int> ii;
const int MX_N = 100010;
int N, a[MX_N];
const int CAP = 200;
int memo[2][CAP+1][2];
int pfs[CAP+1][2];
const int MOD = 998244353;

int main(){
    scanf("%d",&N);
    for(int i =0; i < N; ++i)
        scanf("%d", a+i);
    //base
    bool row = 0;
    if(a[0]==-1)
        for(int i = 1; i <= CAP; ++i)
            memo[row][i][1] = 1;
    else
        memo[row][a[0]][1] = 1;

    for(int pos = 1; pos < N; ++pos){
        for(int c = 1; c <= CAP; ++c){
            pfs[c][0] = mdadd(pfs[c-1][0], memo[row][c][0]);
            pfs[c][1] = mdadd(pfs[c-1][1], memo[row][c][1]);
        }
        row = !row;
        for(int c = 1; c <= CAP; ++c){
            memo[row][c][0] = memo[row][c][1] = 0;
            if(a[pos] != -1 && a[pos] != c)
                continue;
            //b = 1
            memo[row][c][1] = mdadd(memo[row][c][1], pfs[c][1]);
            memo[row][c][1] = mdadd(memo[row][c][1], mdadd(pfs[CAP][0], -pfs[c][0]));
            //b = 0
            memo[row][c][0] = memo[!row][c][1];
            memo[row][c][0] = mdadd(memo[row][c][0], mdadd(pfs[CAP][0], -pfs[c][0]));
        }
    }
    int ans = 0;
    for(int i = 1; i <= CAP; ++i)
        ans = mdadd(ans, memo[row][i][0]);
    printf("%d\n", ans);
    return 0;
}
