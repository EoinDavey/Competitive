#include<iostream>
#include<cstdio>

using namespace std;

char set[] = {'+','_',')','(','*','&','^','%','$','#','@','!','.','/',',',';','{','}'};

int main(){
    int N,S; cin >> N;
    bool lc,uc,dig,sym;
    string s;
    for(int n = 0; n < N; n++){
        cin >> S;
        cin >> s;
        lc=uc=dig=sym=false;
        for(int i = 0; i < S; i++){
            if(s[i] >= 'a' && s[i] <= 'z')
                lc = true;
            if(s[i] >= 'A' && s[i] <= 'Z')
                uc = true;
            if(s[i] >= '0' && s[i] <= '9')
                dig = true;
            for(int j = 0; j < sizeof(set)/sizeof(char); j++)
                if(s[i]==set[j])
                    sym=true;
        }
        if(lc&&uc&&dig&&sym&&(S >= 12)) cout << "valid\n";
        else cout << "invalid\n";
    }
    return 0;
}
