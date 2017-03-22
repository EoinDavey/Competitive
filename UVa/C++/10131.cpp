#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

struct e{
    int w,iq,i;

    e(int _w, int _iq, int _i) : w(_w), iq(_iq), i(_i) {}
    e(){}

    bool operator < (e r) const {
        if(w!=r.w) return w < r.w;
        return iq < r.iq;
    }
};

vector<e> list;
int dp[1111];
int p[1111];

void pr(int v){
    if(v==-1)
        return;
    pr(p[v]);
    cout << list[v].i << endl;
}

int main(){
    int w,iq,i;
    i = 1;
    memset(p,-1,sizeof(p));
    while(scanf("%d %d",&w,&iq)==2){
        list.push_back(e(w,iq, i++));
    }
    int N = list.size();
    sort(list.begin(), list.end());
    int mx=0;
    for(i=0; i < N; i++)
        dp[i] = 1;
    for(i = 1; i < N; i++){
        for(int j = 0; j < i; j++){
            if(list[j].w < list[i].w && list[j].iq > list[i].iq){
                if(dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    p[i] = j;
                }
            }
        }
    }
    /*for(i = 0; i < N; i++)
        printf("(%d,%d) ",list[i].w, list[i].iq);
    cout << endl;
    for(i = 0; i < N; i++)
        printf("%d ",dp[i]);
    cout << endl;*/
    int a = 0;
    for(i =0; i < N; i++)
        if(dp[i]>dp[a])
            a = i;
    cout << dp[a] << endl;
    pr(a);
    return 0;
}
