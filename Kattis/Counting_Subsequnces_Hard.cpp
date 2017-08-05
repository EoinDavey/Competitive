#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

int main(){
    int T; scanf("%d",&T);
    while(T--){
        int N; scanf("%d",&N);
        long long cmf[N],a[N];
        map<long long,int> totCnt;
        totCnt[0]=1;
        for(int i = 0; i < N; i++){
            scanf("%lld",&a[i]);
            cmf[i] = a[i] + (i>0 ? cmf[i-1]:0);
        }
        int cnt = 0;
        for(int i = 0; i < N; i++){
            cnt+=totCnt[cmf[i]-47];
            totCnt[cmf[i]]++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
