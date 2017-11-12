#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int N; cin >> N;
    string ss[N];
    for(int i = 0; i < N; ++i)
        cin >> ss[i];
    int cnt[26];
    for(int i = 0; i < N; ++i){
        memset(cnt,0,sizeof(cnt));
        for(char c : ss[i])
            cnt[c-'a']++;
        for(int i = 0; i < 26; ++i){
            if(cnt[i]>1){
                cout << "NO\n";
                return 0;
            }
        }
    }
    string out = "";
    for(int i = 0; i < N; ++i){
    }
    return 0;
}
