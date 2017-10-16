#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,K; scanf("%d %d",&N,&K);
    int xs[N];
    for(int i = 0; i< N; ++i)
        scanf("%d",&xs[i]);
    int mx = 0;
    queue<int> q;

    for(int i = 0; i < N; ++i){
        while(!q.empty() && q.front() + 1000 <= xs[i])
            q.pop();
        q.push(xs[i]);
        mx = max(mx,((int)q.size()));
    }
    printf("%d\n", ((int)ceil((mx*1.0)/K)));
}
