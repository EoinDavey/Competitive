#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    pair<int,int> arr[N];
    int in;
    for(int i = 0; i < N; i++){
        scanf("%d",&in);
        arr[i] = make_pair(in,i);
    }
    sort(arr,arr+N, greater<pair<int, int> >());
    for(int i = 0; i < N/2;i++){
        printf("%d %d\n",arr[i].second+1,arr[N-i-1].second+1);
    }
    return 0;
}
