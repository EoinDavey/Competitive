#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct tr {
    string w;
    bool c;
    tr(string _w, bool _c) : w(_w), c(_c){}
};

map<string,vector<tr> > mp;

int N;

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    string in;
    vector<string> sentence;
    for(int i = 0; i < N; ++i){
        cin >> in;
        sentence.push_back(in);
    }
    int M; cin >> M;
    string d,e,c;
    for(int i = 0; i < M; ++i){
        cin >> d >> e >> c;
        mp[d].push_back(tr(e,c=="correct"));
    }
    ll cor,tot;
    cor=tot=1LL;
    for(int i = sentence.size()-1; i >=0; --i){
        ll ncor = 0LL;
        for(auto t : mp[sentence[i]]){
            if(t.c)
                ncor++;
        }
        cor*=ncor;
        tot*=((ll)mp[sentence[i]].size());
    }
    if(tot==1){
        bool inc = false;
        for(auto w : sentence){
            auto s = mp[w][0];
            cout << s.w << " ";
            if(!s.c)
                inc=true;
        }
        cout << endl;
        if(inc)
            cout << "incorrect\n";
        else
            cout << "correct\n";
        return 0;
    }
    cout << cor << " correct\n";
    cout << tot-cor << " incorrect\n";
    return 0;
}
