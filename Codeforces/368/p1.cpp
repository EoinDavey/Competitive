#include<iostream>
#include<cstdio>

using namespace std;

int N,M;

int main(){
    cin >> N >> M;
    bool c = false;
    char ch;
    for(int i = 0; i < N&&!c;i++){
        for(int j = 0; j < M&&!c;j++){
           scanf("%c",&ch);
           if(ch==' '||ch=='\n')j--;
           else if(ch=='C'||ch=='M'||ch=='Y')c=true;
        }
    }
    if(c)cout << "#Color" << endl;
    else cout << "#Black&White" << endl;
    return 0;
}
