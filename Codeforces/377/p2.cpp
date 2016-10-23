#include<iostream>
#include<cstdio>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int N,K;
int sched[501],newS[501];

int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        scanf("%d",&sched[i]);
    }
    int prev = K - sched[0];
    int cnt=0;
    for(int i = 0; i < N; i++){
        if(prev + sched[i]<K){
            newS[i]= K-(sched[i]+prev);
            cnt+=newS[i];
        }
        prev = sched[i]+newS[i];
    }
    cout << cnt << endl;
    for(int i = 0; i < N; i++){
        cout << sched[i] + newS[i];
        if(i<N-1)cout<<" ";
        else cout << endl;
    }
    return 0;
}
