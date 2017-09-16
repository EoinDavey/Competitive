#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

constexpr int MX_SZ = 400002;
int lInd = 0;

unordered_map<string,int> indMap;

int p[MX_SZ];

int find(int i) { return p[i] = (i==p[i] ? i : find(p[i]));}

void join(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa!=pb){
        p[pa]=pb;
    }
}

int insert(string s){
    if(indMap.find(s)==indMap.end()){
        indMap[s] = ++lInd;
        p[lInd]=lInd;
        return lInd;
    }
    return indMap[s];
}

int main(){
    ios::sync_with_stdio(false);
    int N; cin>>N;
    vector<ii> nList;
    unordered_set<string> all;
    string x,k,y,ex,ey;
    int ix,iy,iey,iex;
    for(int i = 0; i < N; ++i){
        cin >> x >> k >> y;
        ix = insert(x);
        iy = insert(y);
        if(k=="is")
            join(ix,iy);
        else
            nList.push_back(make_pair(ix,iy));
        all.insert(x);
        all.insert(y);
    }
    for(const auto s : all){
        ix = indMap[s];
        if(s.size() >= 3){
            ex = s.substr(s.size()-3);
            iex = insert(ex);
            join(ix,iex);
            ex = s.substr(s.size()-2);
            if(all.find(ex)!=all.end())
                join(ix,indMap[ex]);
            ex = s.substr(s.size()-1);
            if(all.find(ex)!=all.end())
                join(ix,indMap[ex]);
        } else if(s.size() == 2){
            ex = s.substr(s.size()-1);
            if(all.find(ex)!=all.end())
                join(ix,indMap[ex]);
        }
    }
    bool fail = false;
    for(const auto i : nList)
        if(find(i.first) == find(i.second))
            fail = true;
    if(fail)
        cout << "wait what?\n";
    else
        cout << "yes\n";
    return 0;
}
