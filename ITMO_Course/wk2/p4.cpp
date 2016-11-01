#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<iomanip>
#include<stack>
#define FILE_IN "brackets.in"
#define FILE_OUT "brackets.out"
#ifdef JUDGE
#include<fstream>
std::ifstream cin(FILE_IN);
std::ofstream cout(FILE_OUT);
#else
#include<iostream>
#endif

using namespace std;

string in;

int main(){
    while(getline(cin,in)){
        stack<char> s;
        bool b = false;
        for(int i = 0; i < in.length()&&!b; i++){
            switch (in[i]){
                case ')':
                   if(s.empty())b=true;
                   else if (s.top()=='(')s.pop();
                   else b=true; 
                   break;
                case ']':
                   if(s.empty())b=true;
                   else if (s.top()=='[')s.pop();
                   else b=true; 
                   break;
                default:
                   s.push(in[i]);
                   break;
            }
        }
        if(!s.empty())b=true;
        if(!b)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
