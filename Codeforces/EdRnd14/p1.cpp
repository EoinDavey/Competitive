#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int main(){
    int N;
    cin >> N;
    string s;
    getline(cin,s);
    int b;
    int c = 0;
    for(int i = 0; i < N; i++){
        scanf("%d",&b);
        if(b)c++;
    }
    if(N==1){ if(c==1)cout << "YES"<< endl;
    else cout << "NO";}
    else if(c==N-1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
