#include<iostream>
#include<cstdio>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int main(){
    int N; cin >> N;
    int a,d;
    a=d=0;
    char c;
    for(int i = 0; i < N; i++){
        scanf("%c",&c);
        if(c=='\n')i--;
        else if(c=='A')a++;
        else d++;
    }
    if(a>d)cout << "Anton\n";
    else if (d>a) cout << "Danik\n";
    else cout << "Friendship\n";
    return 0;
}
