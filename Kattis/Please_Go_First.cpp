#include<bits/stdc++.h>
using namespace std;

map<char,int> lInd;

int waitTime(string s){
    map<char,int> last;
    for(int i = 0; i < s.size(); i++)
        last[s[i]] = i;
    int tm = 0;
    for(int i = 0; i < s.size(); i++)
        tm += last[s[i]]*5;
    return tm;
}

int main(){
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while(~--T){
        int _N; cin >> _N;
        string in; cin >> in;
        for(int i = 0; i < in.size(); i++)
            lInd[in[i]] = i;
        int bf = waitTime(in);
        sort(in.begin(), in.end(), [](char a, char b){ return lInd[a]<lInd[b]; });
        cout << bf-waitTime(in) << endl;
    }
    return 0;
}
