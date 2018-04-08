#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int MX_N = 100001;
unordered_map<string,int> indMap;
int indCnt;
int N;
vector<int> yrs[MX_N];

inline int ins(const string& s){
    if(int i = indMap[s])
        return i;
    indMap[s]=++indCnt;
    return indCnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string x; int y;
    cin >> N;
    vector<ii> l;
    l.reserve(N);
    for(int i = 0; i < N; ++i){
        cin >> x >> y;
        int j = ins(x);
        l.push_back({y,j});
    }
    sort(l.begin(),l.end());
    for(const ii &p : l){
        yrs[p.second].push_back(p.first);
    }
    int Q; cin >> Q;
    while(Q-->0){
        cin >> x >> y;
        cout << yrs[indMap[x]][y-1] << endl;
    }
    return 0;
}
