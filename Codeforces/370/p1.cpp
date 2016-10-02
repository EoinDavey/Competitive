#include<iostream>
#include<cstdio>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    int arr[N];
    int output[N];
    memset(output,0,sizeof(output));
    for(int i = 0; i < N; i++){
        scanf("%d",&arr[i]);
    }
    int wrk,n;
    bool b=true;
    wrk=0;
    for(int i = N-1; i>=0; i--){
        n=arr[i]-wrk;
        output[i]=n;
        wrk+=n;
        wrk*=-1;
    }
    for(int i = 0; i < N; i++){
        cout << output[i] << " ";
    }
    cout << endl;
    return 0;
}
