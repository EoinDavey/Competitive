#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char * arr;
int N;
int cnt[3];

int main(){
    arr = new char[1000001];
    scanf("%s",arr);
    N = strlen(arr);
    ll sum = 0;
    for(int i = 0; i < N; i++){
        cnt[arr[i]-'0']++;
        if(arr[i]=='0')
            sum+=(ll)cnt[1]+cnt[2];
        if(arr[i]=='1')
            sum+=(ll) cnt[2];
    }
    printf("%lld\n",sum);
    delete arr;
    return 0;
}
