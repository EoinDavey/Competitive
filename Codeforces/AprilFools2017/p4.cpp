#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int pal[] = {8,-1,-1,3,6,9,4,7,0,5};

int main(){
    string s;getline(cin,s);
    bool p = true;
    for(int i = 0; i < (s.length()+1)/2 && p; i++){
        int v = s[i]-'0';
        int u = s[s.length()-1-i] - '0';
        if(u!=pal[v])
            p=false;
    }
    if(p)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
