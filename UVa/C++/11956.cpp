#include<iostream>
#include<cstring>
#include<stdint.h>
using namespace std;

constexpr int MD = 100;

char hx(uint8_t i) {
    if(i < 10)
        return '0' + i;
    return 'A' + (i-10);
}

void prHx(uint8_t i) {
    uint8_t lo = i & 15;
    uint8_t hi = (i - lo) >> 4;
    cout << ' ' << hx(hi) << hx(lo);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    string in; getline(cin,in);
    for(int t = 1; t <= T; ++t) {
        uint8_t set[100];
        memset(set,0,sizeof(set));
        int ptr = 0;
        getline(cin, in);
        for(char c : in) {
            switch(c){
                case '>':
                    ptr = (ptr + 1) %MD;
                    break;
                case '<':
                    ptr = (((ptr - 1) % MD) + MD) % MD;
                    break;
                case '+':
                    set[ptr]++;
                    break;
                case '-':
                    set[ptr]--;
                    break;
            }
        }
        cout << "Case " << t << ':';
        for(int i = 0; i < 100; ++i){
            prHx(set[i]);
        }
        cout << endl;
    }
    return 0;
}
