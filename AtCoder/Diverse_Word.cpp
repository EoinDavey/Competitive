#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    if(s.size()< 26){
        set<char> st;
        for(char i = 'a'; i<='z'; ++i)
            st.insert(i);
        for(char c : s)
            st.erase(c);
        char mn = 'z';
        for(char c : st)
            mn = min(mn,c);
        cout << s << mn << endl;
    } else if(s=="zyxwvutsrqponmlkjihgfedcba"){
        cout << "-1" << endl;
    } else {
        string cs = s;
        next_permutation(cs.begin(),cs.end());
        for(int i = 0; i < s.size(); ++i)
            if(cs[i]==s[i])
                cout << cs[i];
            else{
                cout << cs[i];
                break;
            }
        cout << endl;
    }
    return 0;
}
