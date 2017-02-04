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
    int l,r;
    int min = N;
    for(int i = 0; i < M; i++){
        scanf("%d %d",&l,&r);
        if(r-l+1 < min) min = r-l+1;
    }
    cout << min << endl;
    for(int i = 0; i < N; i++)
        cout << i % min << " ";
    cout << endl;
    return 0;
}
