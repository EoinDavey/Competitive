#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<iomanip>
#define FILE_IN "postfix.in"
#define FILE_OUT "postfix.out"
#ifdef JUDGE
#include<fstream>
std::ifstream cin(FILE_IN);
std::ofstream cout(FILE_OUT);
#else
#include<iostream>
#endif

using namespace std;

stack<int> s;

int main(){
    string in;
    getline(cin,in);
    for(int i =0 ; i < in.size(); i++){
        int A,B;
        switch (in[i]){
            case '*':
                A = s.top();s.pop();
                B = s.top();s.pop();
                s.push(A*B);
                break;
            case '+':
                A = s.top();s.pop();
                B = s.top();s.pop();
                s.push(A+B);
                break;
            case '-':
                A = s.top();s.pop();
                B = s.top();s.pop();
                s.push(B-A);
                break;
            case ' ':
                break;
            default:
                s.push(((int)in[i]-'0'));
                break;
        }
    }
    cout << s.top() << endl;
    return 0;
}
