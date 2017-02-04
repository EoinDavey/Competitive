#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

long long int N,a,b,c;

int main(){
    cin >> N >> a >> b >> c;
    int m = 4- N%4;
    long long int min = 3*a+3*b+3*c;
    if(m==4) min = 0;
    if(m==1){
        min = (a < min) ? a:min;
        min = (c + b < min) ? c + b:min;
        min = (3*c < min) ? 3*c:min;
    }
    if(m==2){
        min = (2*a < min) ? 2*a:min;
        min = (b < min) ? b:min;
        min = (2*c < min) ? 2*c:min;
    }
    if(m==3){
        min = (c < min) ? c:min;
        min = (3*a < min) ? 3*a:min;
        min = (b + a < min)? b + a: min;
    }
    cout << min << endl;
    return 0;
}
