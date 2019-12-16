#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll base[] = {0LL, 1LL, 0LL, -1LL};
vll csm;
vi ls;

int nv(const vi& inp, int pos, const vll& csm){
    if(pos == 0)
        return 0;
    ll sm = 0;
    int c = 0;
    for(int i = 0; i < inp.size(); i += pos){
        sm += (csm[min(i + pos - 1, ((int)inp.size())-1)] - (i ? csm[i-1] : 0LL))*base[c];
        c = (c+1)%4;
    }
    return abs(sm)%10;
}

void bcsm(const vi& ls){
    csm.resize(ls.size());
    csm[0] = ls[0];
    for(int i = 1; i < ls.size(); ++i)
        csm[i] = ((ll)ls[i]) + csm[i-1];
}

void nph(){
    bcsm(ls);
    for(int x = 0; x < ls.size(); ++x)
        ls[x] = nv(ls, x, csm);
}

void solve(){
    for(int t = 0; t < 100; ++t)
        nph();
}

int main(){
    vi inp;
    string s; cin >> s;
    for(char x : s)
        inp.push_back(x-'0');
    ls = inp;
    ls.insert(ls.begin(), 0);
    solve();
    for(int i = 1; i < 9; ++i)
        printf("%d", ls[i]);
    putchar('\n');

    int offset = 0;
    for(int i = 0; i < 7; ++i)
        offset = offset*10 + inp[i];
    ls.resize(inp.size()*10000 + 1);
    ls[0] = 0;
    for(int t = 0; t < 10000; ++t)
        for(int i = 0; i < inp.size(); ++i)
            ls[1 + t*inp.size() + i] = inp[i];
    solve();
    for(int i = offset+1; i < offset+9; ++i)
        printf("%d", ls[i]);
    putchar('\n');
    return 0;
}
