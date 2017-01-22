#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int main(){
    int N; cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++)
        scanf("%d",&arr[i]);
    sort(arr, arr + N);
    int t; cin >> t;
    cout << upper_bound(arr, arr+N, t) - arr << endl;
    return 0;
}
