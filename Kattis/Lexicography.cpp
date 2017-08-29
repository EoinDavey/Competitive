#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fmemo[30];

ll fac(int u){
    if(fmemo[u]!=0)
        return fmemo[u];
    if(u<=1)
        return 1LL;
    return fmemo[u] = ((ll) u) * fac(u-1);
}

ll nAnagrams(string s){
    ll full = fac(s.size());
    int cnt[30]; memset(cnt,0,sizeof(cnt));
    for(auto i = s.begin(); i != s.end(); i++)
        cnt[*i-'A']++;
    for(int i = 0; i < 30; i++){
        full /= fac(cnt[i]);
    }
    return full;
}

void nthAnagram(string in, ll n){
    for(int i = 0; i < in.size(); i++){
        if(i >0 && in[i]==in[i-1])
            continue;
        string sub = in;
        sub.erase(sub.begin()+i);
        ll jmpsz = nAnagrams(sub);
        if(n <= jmpsz){
            putchar(in[i]);
            nthAnagram(sub,n);
            break;
        }
        n-=jmpsz;
    }
}

int main(){
    string in; ll K;
    while(1){
        cin >> in >> K;
        if(in=="#")
            break;
        sort(in.begin(),in.end());
        nthAnagram(in,K);
        putchar('\n');
    }
    return 0;
}
