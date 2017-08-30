#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;

ll primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
const int MX_SZ=15005;
ll vals[MX_SZ];
int N;
string strsin[MX_SZ];
int order[MX_SZ];

int main(){
    ios::sync_with_stdio(false);
    while(cin >> strsin[N++]){}
    for(int i = 0; i < N; i++)
        order[i]=i;
    sort(order,order+N,[](int u, int v){return strsin[u].size() > strsin[v].size();});
    for(int i = 0; i < N; i++){
        ll x = 1;
        for(auto j = strsin[i].begin(); j != strsin[i].end(); j++)
            x*=primes[*j-'a'];
        vals[i] = x;
    }
    bool fail[N]; memset(fail,0,sizeof(fail));
    for(int i = 0; i < N; i++){
        if(fail[order[i]])
            continue;
        ll x = vals[order[i]];
        for(int j = i+1; j < N; j++)
            if(x > vals[order[j]] && x%vals[order[j]]==0)
                fail[order[j]]=true;
    }
    vector<string> out;
    for(int i = 0; i < N; i++)
        if(!fail[i])
            out.push_back(strsin[i]);
    sort(out.begin(),out.end());
    for(auto i = out.begin(); i != out.end(); i++)
        cout << *i << endl;
    return 0;
}
