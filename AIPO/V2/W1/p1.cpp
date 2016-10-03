#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<cstring>
#include<cstdint>

using namespace std;

uint64_t A,B;

int main(){
    cin >> A >> B;
    uint64_t w=0;
    uint64_t W;
    int cnt = 0;
    for(int i = 1; i<=64; i++){
        W=0ULL;
        for(int j = 0; j < i; j++){
            W|=(1ULL<<j);
        }
        for(int j = 0; j < i-1; j++){
            w=W;
            w&=~(1ULL<<j);
            if(w>=A&&w<=B) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
