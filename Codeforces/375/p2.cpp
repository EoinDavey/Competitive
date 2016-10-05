#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>

using namespace std;

string in;

int main(){
    int N;
    cin >> N;
    scanf("%c",&N);
    getline(cin,in);
    bool b = false;
    int w = 0;
    int maxOut = 0;
    int count = 0;
    for(int i = 0; i < in.length(); i++){
        if(in[i]=='('){
                if(w>maxOut)maxOut=w;
                w=0;
                b=true;
        }else if(in[i]==')'){
            b = false;
            if(w>0)count++;
            w=0;
        }else if(in[i]=='_'){
            if(b){
                if(w>0)count++;
            }else{
                if(w>maxOut)maxOut=w;
            }
            w=0;
        }else{
            w++;
        }
    }
    if(w>maxOut)maxOut=w;
    cout << maxOut << " " << count << endl;
    return 0;
}
