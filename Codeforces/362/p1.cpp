#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>

using namespace std;

int T,S,X;

int main(){
    cin >> T >> S >> X;
    bool b=false;
    if(T==X)b=true;
    else if(X<T||X==T+1)b=false;
    else{
        int end = X-T;
        if(end%S==0||(end-1)%S==0)b = true;
    }
    if(b)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
