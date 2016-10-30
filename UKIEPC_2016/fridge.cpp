#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

string S;

int main(){
    cin >> S;
    int digits[10];
    memset(digits,0,sizeof(digits));
    for(int i = 0; i < S.size(); i++){
        int r = (((int) S[i] - '0')-1)%10;
        if(r==-1)r=9;
        digits[r]++;
    }
    int min, ans;
    min = 1002;
    ans = 0;
    for(int i = 0; i < 10; i++){
        if(digits[i] < min)min=digits[i],ans=i;
    }
    if(ans==9){
        cout << 1;
        for(int i = 0; i < digits[ans]+1; i++){
            cout << 0;
        }
        cout << endl;
    } else {
        for(int i = 0; i < digits[ans]+1; i++){
            cout << ans+1;
        }
        cout << endl;
    }
    return 0;
}
