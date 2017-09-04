#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; scanf("%d",&N);
    vector<pair<int,string> > cups;
    string in;
    int r;
    for(int i = 0; i < N; i++){
        cin >> in;
        if(in[0] >= 'a' && in[0] <= 'z'){
            cin >> r;
            cups.push_back(make_pair(r,in));
        } else {
            r = stoi(in);
            cin >> in;
            cups.push_back(make_pair(r/2,in));
        }
    }
    sort(cups.begin(),cups.end());
    for(auto j = cups.begin(); j != cups.end(); j++){
        cout << j->second << endl;
    }
    return 0;
}
