#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int N,M;

int main(){
    cin >> N >> M;
    int f[N],sum[N];
    for(int i = 0; i < N; i++)scanf("%d",&f[i]);
    sum[0] = f[0];
    for(int i = 1;i < N; i++)sum[i] = f[i] + sum[i-1];
    int l,r,s,cnt;
    cnt = 0;
    for(int i = 0; i < M; i++){
        scanf("%d %d",&l,&r);
        s = sum[r-1] - ((l>1) ? sum[l-2] : 0);
        if(s > 0) cnt+=s;
    }
    cout << cnt << endl;
    return 0;
}
