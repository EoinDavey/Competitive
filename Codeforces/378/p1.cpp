#include<iostream>
#include<cstdio>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int main(){
    string s;
    cin >> s;
    int mx = 0;
    int prev = -1;
    for(int i = 0; i < s.size(); i++){
        char c= s[i];
        if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='Y'){
            int dis = i-prev;
            if(dis>mx)mx = dis;
            prev=i;
        }
    }
    if(s.size()-prev > mx)mx=s.size()-prev;
    cout << mx << endl;
    return 0;
}
