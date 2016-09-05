#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>

using namespace std;

int B;
string A;

int main(){
    char c;
    while(scanf("%c",&c),c!='e'){
        if(c=='.')continue;
        A.push_back(c);
    }
    if(A[A.size()-1]=='0'){
        A=A.substr(0,A.size()-1);
    }
    scanf("%d",&B);
    B++;
    for(int i = 0; i < A.size(); i++){
        if(i==B){
            cout << '.';
        }
        if(A[i]=='f')break;
        cout << A[i];
    }
    for(int i = A.size(); i<B; i++){
        cout << 0;
    }
    cout << endl;
    return 0;
}
