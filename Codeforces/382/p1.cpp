#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int N,K;
string s;

int main(){
    cin >> N >> K;
    cin >> s;
    int i = 0;
    for(; i < N; i++){
        if(s[i] == 'G'||s[i]=='T')break;
    }
    i+=K;
    bool b = false;
    for(; i < N; i+=K){
        if(s[i]=='#') break;
        if(s[i]=='G'||s[i]=='T'){
            b = true;
            break;
        }
    }
    if(b)cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
