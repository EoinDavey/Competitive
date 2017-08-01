#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long 
#define ii pair<ll,int>

using namespace std;

int main(){
    int N,F; scanf("%d %d",&N,&F);
    ll l[N];
    ll r[N];
    ii list[N];
    for(int i = 0; i < N; i++){
        scanf("%lld %lld",&l[i],&r[i]);
        list[i] = make_pair(min(2*l[i],r[i]) - min(l[i],r[i]), i);
    }
    sort(list,list+N,greater<ii>());
    ll sm=0;
    for(int i = 0; i < F; i++){
        int pos = list[i].second;
        sm+=min(2*l[pos],r[pos]);
    }
    for(int i = F; i < N; i++){
        int pos = list[i].second;
        sm+=min(l[pos],r[pos]);
    }
    printf("%lld\n",sm);
    return 0;
}
