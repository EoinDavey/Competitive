#include<bits/stdc++.h>
using namespace std;

int main(){
    string ins; cin >> ins;
    vector<int> tgt;
    for(char s : ins)
        tgt.push_back(s-'0');
    vector<int> l, curW;
    l.push_back(3);
    l.push_back(7);
    int cur[] = {0, 1};
    curW.push_back(3);
    curW.push_back(7);

    for(;;){
        if(l.size() > 20195890){
            cout << "whut" << endl;
            break;
        }
        int n = l[cur[0]] + l[cur[1]];
        if(n > 9){
            l.push_back(1);
            l.push_back(n-10);
            curW.push_back(1);
            curW.push_back(n-10);
        } else{
            l.push_back(n);
            curW.push_back(n);
        }
        while(curW.size() > tgt.size())
            curW.erase(curW.begin());
        if(curW == tgt){
            cout << l.size() - tgt.size() << endl;
            break;
        }
        cur[0] = (cur[0] + 1 + l[cur[0]]) % l.size();
        cur[1] = (cur[1] + 1 + l[cur[1]]) % l.size();
    }
}
