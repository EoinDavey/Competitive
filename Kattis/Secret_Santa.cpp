#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#include<iomanip>

using namespace std;

int main(){
    long long int N;
    cin >> N;
    double arr[] = {1,0.5,0.666666667,0.625,0.63333333333,0.631944444, 0.6321428571,0.6321180556,0.6321208113,0.6321205357,0.6321205608,0.6321205587};
    double ans;
    if(N<=11){
        ans = arr[N-1];
    } else {
        ans = arr[11];
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
