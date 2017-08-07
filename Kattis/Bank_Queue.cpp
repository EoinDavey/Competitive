#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#define ll long long
#define ii pair<ll,ll>

using namespace std;

int main(){
    int N,T; scanf("%d %d",&N,&T);
    map<int,vector<ll>> mp;
    priority_queue<ll> q;
    ll _c, _t;
    for(int i = 0; i < N; i++){
        scanf("%lld %lld",&_c,&_t);
        mp[_t].push_back(_c);
    }
    ll sum = 0;
    for(int i = T-1; i >=0; i--){
        for(auto j = mp[i].begin(); j!=mp[i].end(); j++){
            q.push((*j));
        }
        if(!q.empty()){
            sum+=q.top(); q.pop();
        }
    }
    printf("%lld\n",sum);
    return 0;
}
