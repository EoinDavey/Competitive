#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<map>

using namespace std;

int N;
long long arr[1000001];
int cnt[1000001];

void something( int jump, int inc) {
    int i = 0;
    while( i < N ) {
        arr[i] = arr[i] + ((long long)inc);
        i = i + jump;
    }
}

int main(){
    cin >> N;
    int K; cin >> K;
    int X;
    for(int i = 0; i < K; i++){
        scanf("%d",&X);
        cnt[X]++;
    }
    for(int i= 0; i < N; i++){
        if(cnt[i]>0){
            something(i, cnt[i]);
        }
    }
    for(int i =1; i < N; i++){
        arr[i]+=arr[i-1];
    }
    int Q,L,R; cin >> Q;
    for(int i = 0; i < Q; i++){
        scanf("%d %d",&L,&R);
        printf("%lld\n",arr[R] - ((L>0) ? arr[L-1] : 0L));
    }
    return 0;
}
