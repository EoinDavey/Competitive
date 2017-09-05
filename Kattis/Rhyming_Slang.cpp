#include<bits/stdc++.h>
using namespace std;

bool endsWith(string a, string b){
    if(b.size() > a.size())
        return false;
    int i = a.size() - b.size();
    for(int j = 0; j < b.size(); j++,i++){
        if(a[i]!=b[j])
            return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    string S; cin >> S;
    int E; cin>> E;
    vector<string> sin;
    vector<string> ends;
    string in; getline(cin,in);
    for(int i = 0; i < E; i++){
        bool r = false;
        getline(cin,in);
        stringstream ss(in);
        while(ss >> in){
            sin.push_back(in);
            if(endsWith(S,in))
                r=true;
        }
        if(r)
            for(auto j = sin.begin(); j != sin.end(); j++)
                ends.push_back(*j);
        sin.clear();
    }
    int P; cin >> P;
    getline(cin,in);
    for(int i = 0; i < P; i++){
        getline(cin,in);
        bool suc = false;
        for(auto j = ends.begin(); j != ends.end() && !suc; j++){
            if(endsWith(in,*j))
                suc=true;
        }
        if(suc)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
