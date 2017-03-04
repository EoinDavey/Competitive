#include<iostream>
#include<cstdio>

using namespace std;
    
int cnt[26];

int main(){
    int N; cin >> N;
    string s;
    cin >> s;
    for(int i = 0; i < N; i++){
        cnt[s[i]-'a']++;
    }
    int mx = 0;
    for(int i = 0; i < 26; i++)
        if(cnt[i] > cnt[mx])mx = i;
    printf("%c %d\n",mx+'a',cnt[mx]);
    return 0;
}
