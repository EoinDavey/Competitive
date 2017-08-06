#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>
#define ii pair<int,int>

using namespace std;

bool compare(ii a, ii b){
    return a.first*b.second < b.first*a.second;
}


int main(){
    int N,B;
    while(scanf("%d %d",&N,&B),N!=-1||B!=-1){
        B-=N;
        int _a;
        priority_queue<ii,vector<ii>,decltype(&compare)> q(compare);
        for(int i = 0; i < N; i++){
            scanf("%d",&_a);
            q.push(make_pair(_a,1));
        }
        while(B--){
            ii a = q.top(); q.pop();
            a.second++;
            q.push(a);
        }
        ii a = q.top();
        printf("%d\n",((int) ceil((a.first*1.0)/(a.second*1.0))));
    }
    return 0;
}
