#include<bits/stdc++.h>
using namespace std;

const int MX_N = 504;
const int MX_C = 10000;

struct app{
    int d,s,ind;
    bool operator < (const app& p) const {
        return d - s > p.d - p.s;
    }
};

app a[MX_N];
int N,C;
int memo[MX_N][MX_N];
int INF = 100000000;
vector<int> ans;

int dp(int k, int i){
    if(memo[k][i] != -1)
        return memo[k][i];
    if(k==0)
        return memo[k][i] = 0;
    if(k > i+1)
        return memo[k][i] = INF;
    if(i==0)
        return memo[k][i] = max(a[i].s,a[i].d) <= C ? a[i].s : INF;
    int mn = INF;
    mn = min(mn,dp(k,i-1));
    int p = dp(k-1,i-1);
    if(p + max(a[i].d,a[i].s) <= C)
        mn = min(mn,p+a[i].s);
    return memo[k][i] = mn;
}

void pr(int k, int i){
    if(k==0)
        return;
    if(i==0){
        ans.push_back(a[i].ind);
        return;
    }
    if(memo[k][i] == memo[k][i-1])
        pr(k,i-1);
    else{
        ans.push_back(a[i].ind);
        pr(k-1,i-1);
    }
}

int main(){
    memset(memo,-1,sizeof(memo));
    scanf("%d %d",&N,&C);
    for(int i = 0; i < N; ++i){
        scanf("%d %d",&a[i].d,&a[i].s);
        a[i].ind=i+1;
    }
    sort(a,a+N);
    for(int i = N; i > 0; --i){
        if(dp(i,N-1) < INF){
            printf("%d\n",i);
            pr(i,N-1);
            for(auto j = ans.rbegin(); j != ans.rend(); j++)
                printf("%d ",*j);
            putchar('\n');
            return 0;
        }
    }
    puts("0");
    return 0;
}
