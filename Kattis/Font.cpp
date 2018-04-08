#include<bits/stdc++.h>
using namespace std;
const int MX_N = 26;
int N;
string ss[MX_N];
int sInts[MX_N];

inline int sInt(const string &s){
    int o = 0;
    for(char c : s){
        o |= 1<<(c-'a');
    }
    return o;
}

int subsets(int u,int st){
    if(u==N)
        return st==(1<<26)-1;
    return subsets(u+1,st|sInts[u]) + subsets(u+1,st);
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> ss[i];
        sInts[i] = sInt(ss[i]);
    }
    cout << subsets(0,0) << endl;
    return 0;
}
