#include<iostream>
#include<cstdio>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int L;
int R;

int main(){
    int N;
    cin >> N;
    L=R=0;
    int a[N][2];
    for(int i = 0; i < N; i++){
        cin >> a[i][0] >> a[i][1];
        L+=a[i][0];
        R+=a[i][1];
    }
    int mx= abs(L-R);
    int ans= -1;
    for(int i =0; i < N; i++){
        int newB = abs(L-a[i][0] + a[i][1] - (R - a[i][1] + a[i][0]));
        if(newB>mx) mx = newB, ans = i;
    }
    if(ans==-1)cout << 0<< endl;
    else cout << ans+1 << endl;
    return 0;
}
