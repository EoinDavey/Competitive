#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

char in[] = {'A','b','d','H','I','M','O','o','p','q','T','U','V','v','W','w','X','x','Y'};
char out[] ={'A','d','b','H','I','M','O','o','q','p','T','U','V','v','W','w','X','x','Y'};


int main(){
    string s;
    getline(cin,s);
    int N=s.length();
    bool b = false;
    for(int i = 0;(i < N/2) &&!b; i++){
        bool f = false;
        int j = 0;
        for(; j < sizeof(in)/sizeof(char) && !f; j++){
            if(s[i] == in[j])f=true,j--;
        }
        if(f){
            if(s[N-i-1]!=out[j])b=true;
        } else b = true;
        //printf("i:%d, j:%d, b:%d, f:%d\n",i,j,b,f);
    }
    if(N&1){
        bool f = false;
        int j = 0;
        for(;j<sizeof(in)/sizeof(char)&&!f;j++){
            if(s[N/2]==in[j])f=true,j--;
        }
        if(f){
            if(s[N/2]!=out[j])b=true;
        } else b = true;
    }
    if(!b)cout << "TAK" << endl;
    else cout << "NIE" << endl;
    return 0;
}
