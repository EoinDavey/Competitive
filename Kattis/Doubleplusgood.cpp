#include<bits/stdc++.h>
using namespace std;

int main(){
  string s; cin >> s;
  int n = s.size();
  vector<int> cs;
  for(int i = 0; i < n; ++i)
    if(s[i] == '+')
      cs.push_back(i);

  int m = cs.size();
  set<int> o;

  for(int i = 0; i < (1<<m); ++i){
    int sm = 0;
    int rn = 0;
    set<int> ig;
    for(int j = 0; j < m; ++j)
      if((i&(1<<j))==0)
        ig.insert(cs[j]);

    for(int j = 0; j < n; ++j){
      if(ig.count(j))
        continue;
      if(s[j] == '+'){
        sm += rn;
        rn = 0;
      }else{
        rn = 10*rn + s[j]-'0';
      }
    }
    if(rn)
      sm+=rn;
    o.insert(sm);
  }
  cout << o.size() << endl;
}
