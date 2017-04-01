#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

int main(){
    int N, K; cin >> N >> K;
    priority_queue<int> q;
    int in;
    for(int i = 0; i < N; i++){
        scanf("%d",&in);
        q.push(in);
    }
    int c = 0;
    while(!q.empty()){
        int u = q.top(); q.pop();
        if(u>K){
            c+=u/K;
            if(u%K!=0)q.push(u%K);
        } else c++;
    }
    printf("%d\n",(c+1)/2);
}

